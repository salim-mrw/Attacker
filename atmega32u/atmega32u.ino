#include <Keyboard.h>

#define KEY_ENTER 0xE0
#define KEY_WIN 0x5D
#define KEY_R 0x52
#define KEY_F11 0x7A

char ENTER = KEY_ENTER;
char RK = KEY_R;

void setup() {

  Keyboard.begin();
  
}

void loop() {
    Keyboard.press(RK);
    Keyboard.release(RK);
    delay(200);
    Keyboard.press(RK);
    Keyboard.release(RK);
    delay(200);
    Keyboard.print("CMD");
    delay(200);
    Keyboard.press(ENTER);
    Keyboard.release(ENTER);
    Keyboard.releaseAll();
    Keyboard.end();
}
