#include <Servo.h>
Servo myservo;
const int waterSens = A0;
int pos = 0;
void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}
void loop() {
  int sensorValue = analogRead(waterSens);      
  sensorValue = map(sensorValue, 0, 1023, 0, 180); 
     if (sensorValue >= 50) {
        for (pos = 0; pos <= 180; pos += 1) {
          myservo.write(pos);
            delay(15);}
            
         for (pos = 180; pos >= 0; pos -= 1) {
          myservo.write(pos);
              delay(15);
  }     
     }  
else{
    myservo.write(0);
}
  Serial.println(sensorValue);
  delay(20);        
}
