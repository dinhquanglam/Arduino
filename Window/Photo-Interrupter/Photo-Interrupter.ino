#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int count=0;
int current =0;
int previous =0;
int sensor=7;

void setup() {
  pinMode(sensor,INPUT);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
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
//    else 
//    {
//      digitalWrite(13,LOW);

//    delay(10000); // 10s
//    if (current != previous){
//    if(digitalRead(sensor) == 0){
//      count--;
//     digitalWrite(13,HIGH);
//     lcd.setCursor(3,0);
//     lcd.print("number of");
//     lcd.setCursor(0,1);
//     lcd.print("people now:  ");
//     lcd.print(count);
//     Serial.print("number of people now:  ");
//     Serial.println(count);
//     if( count == 0) {
//      digitalWrite(13,LOW);}
//     }   
//   }

////Serial.print("IRSensorip  ");
////Serial.println(digitalRead(7));
//if(digitalRead(7)==0)
//{
//  digitalWrite(13,HIGH);
//  i++;
//  Serial.println(i);
//  }
// else{
//    digitalWrite(13,LOW);
//    }
//}
