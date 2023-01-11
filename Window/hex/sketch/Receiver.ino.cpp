#include <Arduino.h>
#line 1 "C:\\Users\\Admin\\Documents\\Arduino\\Receiver\\Receiver.ino"
// Created by Dinh Quang Lam
// Date: 18/05/2022
// K64_DA_CLC1_K64_UET
// Hand gesture robots
// Computer Interface Programming_ Dr.Pham Duy Hung

#include <SPI.h>
#include "RF24.h"
#include "nRF24L01.h"
 
int data[2];
RF24 radio(9,10);//thay 10 thành 53 với mega
const uint64_t pipe = 0xE8E8F0F0E1LL; // địa chỉ phát

//dieu khien robot
const int enbA = 5;
const int enbB = 3;
// Chân điều khiển của động cơ
const int IN1 = 4;  
const int IN2 = 6;    
const int IN3 = 7;    
const int IN4 = 8;  

//xác định một biến cho mỗi động cơ
int RightSpd = 20;
int LeftSpd = 20;
int lenSpd = 20; 
int xuongSpd = 20;

 
#line 31 "C:\\Users\\Admin\\Documents\\Arduino\\Receiver\\Receiver.ino"
void setup();
#line 50 "C:\\Users\\Admin\\Documents\\Arduino\\Receiver\\Receiver.ino"
void loop();
#line 31 "C:\\Users\\Admin\\Documents\\Arduino\\Receiver\\Receiver.ino"
void setup(){
  Serial.begin(9600);
  radio.begin();                     
  radio.setAutoAck(1);              
  radio.setDataRate(RF24_1MBPS);    // Tốc độ dữ liệu
  radio.setChannel(10);               // Đặt kênh
  radio.openReadingPipe(1,pipe);     
  radio.startListening();            
  //pinMode(led, OUTPUT);

  pinMode(enbA, OUTPUT);
  pinMode(enbB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
}
 
void loop(){
  if (radio.available()){

       radio.read(data, sizeof(data));
   
      Serial.print("X--");
      Serial.println(data[0]);
      Serial.print("Y--");
      Serial.println(data[1]);

      if(data[0] > 380){
       Serial.println("đi lên");
        analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW); 
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW); 
      digitalWrite(IN4, HIGH);
      }

         if(data[0] < 310){
         Serial.println("đi xuống");
          analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
         }
         

        if(data[1] > 180){
          Serial.println("rẽ phải");
             analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);     
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);;
        }

         if(data[1] < 110){
          Serial.println("rẽ phải");
             analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);     
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

       Serial.println("rẽ trái");
         analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
          digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
         }

          if(data[0] > 330 && data[0] < 360 && data[1] > 130 && data[1] < 160){
            Serial.println("dừng");
            analogWrite(enbA, 0);
             analogWrite(enbB, 0); digitalWrite(IN1, LOW);
  digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
         }
            
          
}
}

        

