// Author: Dinh Quang Lam 
// Work Unit: ĐA-CLC1-K64
// Created: 14-03-2022 -- Finished: 15-03-20022
//  Arduino process: Security System
// SisLab 2022 
// Instructor: Dr.BDHieu


#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
 int led = 13;
 int buzz = 12;

void setup() {
  Serial.begin(9600);// setup Serial Monitor to display information
  pinMode(2, INPUT);// Input from sensor
  pinMode(13, OUTPUT);// OUTPUT to alarm or LED
  lcd.init();
  lcd.backlight();
}

void loop() {
  int motion =digitalRead(2);
  if(motion){
    Serial.println("Motion detected");
    digitalWrite(13,HIGH);
    tone(12, 1000);
    lcd.display();
    lcd.setCursor(2,0); // dua con tro den 2->cot 3, 0->hang 1
    lcd.print("Warning!!!");
    lcd.setCursor(0,1);
    lcd.print("Motion detected");
  }else{
     Serial.println("===nothing moves");
     digitalWrite(13,LOW);
     noTone(12);
     lcd.noDisplay();//Xoá màn hình hiển thị
  }
  delay(500);

}
