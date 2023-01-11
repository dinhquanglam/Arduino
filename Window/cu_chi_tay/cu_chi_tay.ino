#include <SPI.h>        // Thư viện SPI để liên lạc với nRF24L01 +
#include <RF24.h>       // Thư viện chính của nRF24L01 +
#include <Wire.h>       // Để liên lạc
#include <I2Cdev.h>     // Để liên lạc với MPU6050
#include <MPU6050.h>    // Thư viện chính của MPU6050
// đối tượng để truy cập và kiểm tra Gyro và Gia tốc kế 
MPU6050 mpu; 
int16_t ax, ay, az;
int16_t gx, gy, gz;
// Xác định gói cho hướng (trục X và trục Y)
int data[2];
//8 và 10 là số pin kỹ thuật số mà tín hiệu CE và CSN được kết nối.
RF24 radio(9,10);
// địa chỉ ống cho giao tiếp                                  
const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup(void){
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();              // Khởi tạo đối tượng MPU
  radio.begin();                 // Bắt đầu giao tiếp nRF24     
  radio.openWritingPipe(pipe);  
}
void loop(void){
  if(!radio.available()){
    Serial.println("disconnect/");
  }
 
  
   // các giá trị gia tốc và con quay của các trục được lấy.
  // Nếu muốn điều khiển trục xe khác nhau,có thể thay đổi tên trục trong lệnh map.
  
   mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
   
  // Trong điều khiển hai chiều, trục X (dữ liệu [0]) của MPU6050 cho phép robot di chuyển tiến và lùi.
  // Trục Y (dữ liệu [0]) cho phép robot rẽ phải và rẽ trái.


  
 data[0] = map(ax, -17000, 17000, 300, 400 ); // Gửi dữ liệu chục X
  data[1] = map(ay, -17000, 17000, 100, 200);  // Gửi dữ liệu chục Y
  radio.write(data, sizeof(data));

  
}
