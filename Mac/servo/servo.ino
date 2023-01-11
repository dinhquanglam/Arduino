#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos;    // variable to store the servo position

void setup() {
  myservo.attach(D5);  // attaches the servo on pin 9 to the servo object
  Serial.begin(115200);
}

void loop() {
  pos = 0;
       myservo.write(0);              // tell servo to go to position in variable 'pos'

  for (pos = 0; pos <= 20; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println(myservo.read());

    delay(200);                       // waits 15ms for the servo to reach the position
  }
     myservo.write(20);              // tell servo to go to position in variable 'pos'

  
  for (pos = 20; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println(myservo.read());

    delay(100);                       // waits 15ms for the servo to reach the position
  }
}
