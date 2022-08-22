#include <SPI.h>      // Thư viện SPI để liên lạc với nRF24L01
#include "RF24.h"   //Thư viện chính của nRF24L01
#include "nRF24L01.h"
//chân kích hoạt của động cơ
const int enbA = 5;
const int enbB = 3;
const int enbC = A0;
const int enbD = A1;
// Chân điều khiển của động cơ
const int IN1 = 4;  
const int IN2 = 6;    
const int IN3 = 7;    
const int IN4 = 8;    
const int IN5 = A2;   
const int IN6 = A3;
const int IN7 = A4;
const int IN8 = A5;
//xác định một biến cho mỗi động cơ
int RightSpd = 255;
int LeftSpd = 255;
int lenSpd = 255;
int xuongSpd = 255;
// Xác định gói cho hướng (trục X và trục Y)
int data[2];
//8 và 10 là số pin kỹ thuật số mà tín hiệu CE và CSN được kết nối
RF24 radio(9,10);
//địa chỉ ống cho giao tiếp
const uint64_t pipe = 0xE8E8F0F0E1LL;
void setup(){
 // Xác định các chân động cơ OUTPUT
  pinMode(enbA, OUTPUT);
  pinMode(enbB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(enbC, OUTPUT);
  pinMode(enbD, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  Serial.begin(9600);
  radio.begin();                                  // Bắt đầu giao tiếp nRF24          
  radio.openReadingPipe(1, pipe);   // Đặt địa chỉ của máy phát mà chương trình sẽ nhận dữ liệu.
  radio.startListening();             
  }
void loop(){
  if (radio.available()){
    radio.read(data, sizeof(data));
    if(data[0] > 380){
      //Lên        
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW); 
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW); 
      digitalWrite(IN4, HIGH);
      analogWrite(enbC, RightSpd);
      analogWrite(enbD, LeftSpd);
      digitalWrite(IN5, LOW);  
      digitalWrite(IN6, HIGH);
      digitalWrite(IN7, LOW);  
      digitalWrite(IN8, HIGH);
    }    
    if(data[0] < 310){
      //Xuống             
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(enbC, RightSpd);
      analogWrite(enbD, LeftSpd);   
      digitalWrite(IN5, HIGH);
      digitalWrite(IN6, LOW);
      digitalWrite(IN7, HIGH);
      digitalWrite(IN8, LOW);
    }     
    if(data[1] > 180){
      //Trái
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
          digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(enbC, RightSpd);
      analogWrite(enbD, LeftSpd);
      digitalWrite(IN5, LOW);
      digitalWrite(IN6, HIGH);
      digitalWrite(IN7, HIGH);
      digitalWrite(IN8, LOW);
    }
    if(data[1] < 110){
      //Phải
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);     
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(enbC, RightSpd);
      analogWrite(enbD, LeftSpd);
      digitalWrite(IN5, HIGH);
      digitalWrite(IN6, LOW);
      digitalWrite(IN7, LOW);
      digitalWrite(IN8, HIGH);
    }
    if(data[0] > 330 && data[0] < 360 && data[1] > 130 && data[1] < 160){
      //stop 
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
      analogWrite(enbC, 0);
      analogWrite(enbD, 0);
    }
  }
}
