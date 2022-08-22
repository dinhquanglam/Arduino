#include <Servo.h>
Servo myservo;
const int waterSens = A5;
int pos;
int sensorValue =0;
void setup() {
 
  myservo.write(pos); 
  Serial.begin(9600);
  myservo.attach(9);
}
void loop() {
  
  
  sensorValue = analogRead(waterSens);  
  sensorValue = map(sensorValue, 0, 1023, 180, 0);     
  Serial.print("Sensor value: ");
   Serial.print(sensorValue);
   Serial.print(" ");
    Serial.println(pos);
    myservo.write(sensorValue);
    delay(100);
 


//   while( sensorValue >= 50 && pos > 0 ){       
//        pos+=1;           
//        myservo.write(pos);     
//        
// 
//      //  Serial.println(pos); 
//      delay(15);
//         Serial.println("loop1");
//         Serial.println(pos);
//
//     }

     
    //Up
//    while( sensorValue <= 50 && pos <=180 &&  sensorValue <= 10   ){ 
//       
//        pos+=1;           
//        myservo.write(pos);     
//      //  Serial.println(pos); 
//        delay(15);
//         pos = 180;
//           Serial.println("loop2 ");
//
//    }
//      Serial.println("main loop ");
//
//    // Serial.println(sensorValue);
//     delay(20);
//    
}
     
     


     
