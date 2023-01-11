
#include <SPI.h>
#include "RF24.h"
#include <Wire.h>       // Để liên lạc
#include <I2Cdev.h>     // Để liên lạc với MPU6050
#include <MPU6050.h>    // Thư viện chính của MPU6050

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

int data[2];
 
const uint64_t pipe = 0xE8E8F0F0E1LL; // địa chỉ để phát
RF24 radio(9,10); //thay 10 thành 53 với mega
//byte msg[3];
//const int sensor = A0;
//int value = 0;
 
void setup(){ 
  //============================================================Module NRF24
   Serial.begin(9600);
   
   Wire.begin();
  mpu.initialize();              // Khởi tạo đối tượng MPU
  
  radio.begin();                     
  radio.setAutoAck(1);               
  radio.setRetries(1,1);             
  radio.setDataRate(RF24_1MBPS);    // Tốc độ truyền
  radio.setPALevel(RF24_PA_MAX);      // Dung lượng tối đa
  radio.setChannel(10);               // Đặt kênh
  radio.openWritingPipe(pipe);        // mở kênh
  //pinMode(sensor, INPUT);

  
}
 
void loop(){
  //value = analogRead(sensor);
  //msg[0] = value / 4;
  //radio.write(&msg, sizeof(msg));
  //delay(50);

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  delay(100);
   data[0] = map(ax, -17000, 17000, 300, 400 ); // Gửi dữ liệu chục X
  data[1] = map(ay, -17000, 17000, 100, 200);  // Gửi dữ liệu chục Y
  radio.write(data, sizeof(data));

   Serial.print("X-");
   Serial.println(data[0]);

    

    Serial.print("Y-");
    Serial.println(data[1]);
  

   
}
