const char INDEX_HTML[] PROGMEM = R"=====(
  <!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Attacker</title>
    <link rel="stylesheet" href="style.css">
    <link rel="icon" href="logo.png">
  </head>
  <body class="pt-0 pb-5 bg-dark text-light">
    <div id="loader" class="d-flex wh-100">
        <div class="sub-loader"></div>
    </div>
    <nav>
        <div class="nav-list">
            <span id="list" class="cursor-pointer"><svg height="24px" viewBox="0 -960 960 960" width="24px" fill="#0dcaf0"><path d="M784-120 532-372q-30 24-69 38t-83 14q-109 0-184.5-75.5T120-580q0-109 75.5-184.5T380-840q109 0 184.5 75.5T640-580q0 44-14 83t-38 69l252 252-56 56ZM380-400q75 0 127.5-52.5T560-580q0-75-52.5-127.5T380-760q-75 0-127.5 52.5T200-580q0 75 52.5 127.5T380-400Z"/></svg></span>
            <span id="mode" class="cursor-pointer"><svg xmlns="http://www.w3.org/2000/svg" height="24px" viewBox="0 -960 960 960" width="24px" fill="#f8f9fa"><path d="M480-360q50 0 85-35t35-85q0-50-35-85t-85-35q-50 0-85 35t-35 85q0 50 35 85t85 35Zm0 80q-83 0-141.5-58.5T280-480q0-83 58.5-141.5T480-680q83 0 141.5 58.5T680-480q0 83-58.5 141.5T480-280ZM200-440H40v-80h160v80Zm720 0H760v-80h160v80ZM440-760v-160h80v160h-80Zm0 720v-160h80v160h-80ZM256-650l-101-97 57-59 96 100-52 56Zm492 496-97-101 53-55 101 97-57 59Zm-98-550 97-101 59 57-100 96-56-52ZM154-212l101-97 55 53-97 101-59-57Zm326-268Z"/></svg></span>
            <ul>
                <li><a href="#scan"><svg height="24px" viewBox="0 -960 960 960" width="24px" fill="#f8f9fa"><path d="M784-120 532-372q-30 24-69 38t-83 14q-109 0-184.5-75.5T120-580q0-109 75.5-184.5T380-840q109 0 184.5 75.5T640-580q0 44-14 83t-38 69l252 252-56 56ZM380-400q75 0 127.5-52.5T560-580q0-75-52.5-127.5T380-760q-75 0-127.5 52.5T200-580q0 75 52.5 127.5T380-400Z"/></svg></a></li>
                <li><a href="#attack"><svg height="24px" viewBox="0 -960 960 960" width="24px" fill="#f8f9fa"><path d="m422-232 207-248H469l29-227-185 267h139l-30 208ZM320-80l40-280H160l360-520h80l-40 320h240L400-80h-80Zm151-390Z"/></svg></a></li>
                <li><a href="#about"><svg height="24px" viewBox="0 -960 960 960" width="24px" fill="#f8f9fa"><path d="M480-680q-33 0-56.5-23.5T400-760q0-33 23.5-56.5T480-840q33 0 56.5 23.5T560-760q0 33-23.5 56.5T480-680Zm-60 560v-480h120v480H420Z"/></svg></a></li>
            </ul>
        </div>
    </nav>
    <div class="container-fluid">
        <section id="scan" class="wh-aut0 text-align-left">
            <form action="" method="GET" name="scanForm">
                <div class="box border-left-info mt-2 mb-2">  
                    <h5 class="text-info">Scan</h3>
                </div>
                <button type="button" name="scan">Scan</button>
                <button type="button" name="clear">Clear</button>
                <h4 class="text text-info">Setting</h4>
                <div class="d-grid">
                    <label class="text-light mb-2" for="chanal">Channel
                        <select class="text-info" name="chanal" id="chanal">
                            <option value="All">All</option>
                            <option value="1">1</option>
                            <option value="2">2</option>
                            <option value="3">3</option>
                        </select>
                    </label>
                    <label class="text-light mb-2" for="Frequency">Frequency
                        <select class="text-info" name="Frequency" id="Frequency">
                            <option value="All">All</option>
                            <option value="1">2.4 GHZ</option>
                            <option value="2">5.0 GHZ</option>
                        </select>
                    </label>
                    <label class="text-light mb-2" for="devices">Devices
                        <select class="text-info" name="devices" id="devices">
                            <option value="Devices">No Limit</option>
                            <option value="1">5</option>
                            <option value="2">10</option>
                        </select>
                    </label>
                </div>
                <table class="text table text-info mt-1 mb-5">
                    <caption class="text text-info">Access Point</caption>
                    <thead>
                        <tr class="table-info text-info">
                            <th scope="col">#</th>
                            <th scope="col">SSID</th>
                            <th scope="col">MAC</th>
                            <th scope="col">RSSI</th>
                            <th scope="col">Encryption</th>
                            <th scope="col">Channel</th>
                            <th scope="col">Type</th>
                            <th scope="col">Vendor</th>
                            <th><input id="apAll" type="checkbox" name="apAll"></th>
                        </tr>
                    </thead>
                    <tbody id="aptbody">
                    </tbody>
                </table>
                <button type="button" name="reloadSTA">Reload</button>
                <table class="text table text-info mt-1 mb-5">
                    <caption class="text text-info">Station</caption>
                    <thead>
                        <tr class="table-info text-info">
                            <th scope="col">#</th>
                            <th scope="col">Station</th>
                            <th scope="col">IP</th>
                            <th scope="col">MAC</th>
                            <th scope="col">Pkts</th>
                            <th scope="col">Channel</th>
                            <th scope="col">Access Point</th>
                            <th scope="col">Last Seen</th>
                            <th><input type="checkbox" name="staTarget"></th>
                        </tr>
                    </thead>
                    <tbody id="statbody">
                    </tbody>
                </table>
            </form>
        </section>
        <section id="attack" class="wh-aut0 text-align-left">
            <form action="" method="GET" name="attackForm">
                <div class="box border-left-info mt-2 mb-2">  
                    <h5 class="text-info">Attack</h3>
                </div> 
                <button type="button" name="reloadAttack">Reload</button>
                <table class="text table text-info mt-5 mb-5">
                    <thead>
                        <tr class="table-info text-info">
                            <th scope="col">Attack</th>
                            <th scope="col" class="text-align-center">Targets</th>
                            <th scope="col" class="text-align-center">Status</th>
                            <th scope="col" class="text-align-center">Description</th>
                        </tr>
                    </thead>
                    <tbody id="attacktbody">
                    </tbody>
                </table>
            </form>
        </section>
        <section id="about" class="wh-100 about-text d-flex"> 
            <img src="logo.png" alt="icon" class="logo" width="23%" height="40%" loading="lazy"/>
            <p class="text-light text-align-left">
                <span><a href="https://attacker.org" target="_blank" class="text-info">Attacker</a></span> for networking attacks<br /> It is made by 
                <span><a href="https://salim-mrw.com" target="_blank" class="text-info">Salim Marwan</a></span><br /> From 
                <span><a href="https://nit21.net" target="_blank" class="text-info">NIT</a></span> team
                <br /> V 1.0
            </p>
        </section>
    </div>
    <script src="script.js"></script>
  </body>
</html>
)=====";
