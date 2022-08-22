// Author: Dinh Quang Lam 
// Work Unit: ĐA-CLC1-K64
// Created: 16-03-2022 -- Finished: 17-03-20022
//  Arduino process: People Counter 
// SisLab 2022 
// Instructor: Dr.BDHieu


#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int count=0;
int previousin =0;
int currentin =0;
int previousout =0;
int currentout =0;

int in=2;
int out =7;

void setup() {
  pinMode(in,INPUT);
  pinMode(out,INPUT);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // IN SENSOR
 
   currentin = digitalRead(in);  
   if (currentin != previousin){
    if(digitalRead(in) == 0){
      count++; 
      if( count >0){    
     digitalWrite(13,HIGH);}
     lcd.setCursor(3,0);
     lcd.print("number of");
     lcd.setCursor(0,1);
     lcd.print("people now:  ");
     lcd.print(count);
     Serial.print("number of people now:  ");
     Serial.println(count);
    }
}
  previousin = currentin;

  // OUT SENSOR 
  
    currentout = digitalRead(out);  
     if (currentout != previousout){
    if(digitalRead(out) == 0){
      count--;  
     lcd.setCursor(3,0);
     lcd.print("number of");
     lcd.setCursor(0,1);
     lcd.print("people now:  ");
     lcd.print(count);
     Serial.print("number of people now:  ");
     Serial.println(count);
     if(count == 0){
        digitalWrite(13,LOW);
     }
    }
}
    previousout = currentout;
}
  
    



   


 
