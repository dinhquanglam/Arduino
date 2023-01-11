
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // Dia chi mac dinh 0x27(0x3F), 16 cot 2 hang

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,0); // dua con tro den 2->cot 3, 0->hang 1
  lcd.print("Hi everyone");
  lcd.setCursor(0,1);
  lcd.print("Lam dang tryhard");
}

void loop()
{
  
}
