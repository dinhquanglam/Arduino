#include <Servo.h>
Servo myservo;
const int waterSens = A5;
int pos;
int sensorValue =0;


void setup() {
  Serial.begin(9600);
  myservo.write(pos); 
  myservo.attach(9);
}

void loop() {
  
  sensorValue = analogRead(waterSens); // read the analog value from sensor
  sensorValue = map(sensorValue, 0, 1023, 0, 180);     
 
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);

  delay(1000);
}
