#include <Servo.h>
Servo myservo;
const int waterSens = A0;
int pos;
void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}
void loop() {
   while( sensorValue >= 50 && pos >= 0 ){       
        pos-=1;           
        myservo.write(pos);     
      //  Serial.println(pos); 
      delay(15);
       pos = 0;
         Serial.println("loop1");

}
  Serial.println(sensorValue);
  delay(20);        
}
