#include <M5Stack.h>
#include <DHT12.h>
#include <Wire.h>

DHT12 dht12;
void setup() {
    M5.begin();
    Wire.begin();
    M5.Lcd.setTextSize(4);
}

void loop() {
    M5.Lcd.fillScreen(NAVY);
    M5.Lcd.setCursor(0,0);

    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.printf("Temperature:\n %2.2f\n\n", dht12.readTemperature());

    M5.Lcd.setTextColor(PINK);
    M5.Lcd.printf("Humidity:\n %2.2f\n\n", dht12.readHumidity());

    M5.update();
    delay(5000);
}
