#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int count=0;
int current =0;
int previous =0;
int sensor=2;

void setup() {
  pinMode(sensor,INPUT);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
    if(digitalRead(sensor) == 0){ 
        current = digitalRead(sensor);  
   if (current != previous){
    if(digitalRead(sensor) == 0){    
      count++;
     digitalWrite(13,HIGH);
     lcd.setCursor(3,0);
     lcd.print("number of");
     lcd.setCursor(0,1);
     lcd.print("people now:  ");
     lcd.print(count);
     Serial.print("number of people now:  ");
     Serial.println(count);
    }
   }
     previous = current;
}
}
