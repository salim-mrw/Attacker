#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include "index_html.h"
#include "style_css.h"
#include "script_js.h"

#ifndef APSSID
#define APSSID "Attacker"
#define APPSK "Attacker@1"
#define HOST "attacker"
#endif

const char *ssid = APSSID;
const char *password = APPSK;
const char *host = HOST;

ESP8266WebServer server(80);

// DNS attacker.local
// ip http://192.168.4.1
void handleHtml() {
  server.sendHeader("Connection", "close");
  server.send(200, "text/html", INDEX_HTML);
}

void handleCss() {
  server.sendHeader("Connection", "close");
  server.send(200, "text/css", STYLE_CSS);
}

void handleJs() {
  server.sendHeader("Connection", "close");
  server.send(200, "text/javascript", SCRIPT_JS);
}

void setup() {
  delay(1000);
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  //Serial.print(WiFi.channel());
  IPAddress myIP = WiFi.softAPIP();
  WiFi.mode(WIFI_AP_STA);
  MDNS.begin(host);
  server.on("/", HTTP_GET, []() {handleHtml();});
  server.on("/style.css", HTTP_GET, []() {handleCss();});
  server.on("/script.js", HTTP_GET, []() {handleJs();});
  server.begin();
  MDNS.addService("http", "udp", 80);
}

void loop() {
  //Scan
  WiFi.disconnect();
  delay(100);
  String ssid;
  int32_t rssi;
  uint8_t encryptionType;
  uint8_t *bssid;
  int32_t channel;
  bool hidden;
  int scanResult;
  scanResult = WiFi.scanNetworks(/*async=*/false, /*hidden=*/true);
  if (scanResult == 0) {
    Serial.println(F("No networks found"));
  } else if (scanResult > 0) {
    Serial.printf(PSTR("%d networks found:\n"), scanResult);

    // Print unsorted scan results
    for (int8_t i = 0; i < scanResult; i++) {
      WiFi.getNetworkInfo(i, ssid, encryptionType, rssi, bssid, channel, hidden);

      // get extra info
      const bss_info *bssInfo = WiFi.getScanInfoByIndex(i);
      String phyMode;
      const char *wps = "";
      if (bssInfo) {
        phyMode.reserve(12);
        phyMode = F("802.11");
        String slash;
        if (bssInfo->phy_11b) {
          phyMode += 'b';
          slash = '/';
        }
        if (bssInfo->phy_11g) {
          phyMode += slash + 'g';
          slash = '/';
        }
        if (bssInfo->phy_11n) {
          phyMode += slash + 'n';
        }
        if (bssInfo->wps) {
          wps = PSTR("WPS");
        }
      }
      Serial.printf(PSTR("  %02d: [CH %02d] [%02X:%02X:%02X:%02X:%02X:%02X] %ddBm %c %c %-11s %3S %s\n"), i, channel, bssid[0], bssid[1], bssid[2], bssid[3], bssid[4], bssid[5], rssi, (encryptionType == ENC_TYPE_NONE) ? ' ' : '*', hidden ? 'H' : 'V', phyMode.c_str(), wps, ssid.c_str());
      yield();
    }
  } else {
    Serial.printf(PSTR("WiFi scan error %d"), scanResult);
  }
  delay(5000);
  server.handleClient();
  MDNS.update();
}
