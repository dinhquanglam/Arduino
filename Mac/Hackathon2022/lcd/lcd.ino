#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
Wire.begin(19,18); // SDA , SCK
lcd.init();
lcd.backlight();
lcd.print("Hello cac ban");
lcd.setCursor(0,1);
lcd.print("dammedientu.vn !");
}
void loop() {
}
