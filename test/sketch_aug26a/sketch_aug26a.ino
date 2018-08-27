#include <M5Stack.h>

void setup() {
  // put your setup code here, to run once:
  M5.begin();

  M5.Lcd.setTextColor(BLUE);
  M5.Lcd.setTextSize(30);
  M5.Lcd.printf("Chino\nKafuu");
}

void loop() {
  buttonTest();
}

void buttonTest(){

    if(M5.BtnA.wasPressed()) {
        M5.Lcd.clear();
        M5.Lcd.setTextColor(BLUE);
        M5.Lcd.setCursor(0, 0);
        M5.Lcd.printf("Chino\nKafuu");
    }else if(M5.BtnB.wasPressed()) {
        M5.Lcd.clear();
        M5.Lcd.setTextColor(PINK);
        M5.Lcd.setCursor(0, 0);
        M5.Lcd.printf("Cocoa\nHoto");
    }else if(M5.BtnC.wasPressed()) {
        M5.Lcd.clear();
        M5.Lcd.setTextColor(PURPLE);
        M5.Lcd.setCursor(0, 0);
        M5.Lcd.printf("Rise\nTedeza");
    }

    M5.update();
}
