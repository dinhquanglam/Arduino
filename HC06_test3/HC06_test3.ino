#include <SoftwareSerial.h> //Thư viện sử dụng bất kỳ 2 chân digital nào để làm chân TX RX
SoftwareSerial mybluetooth(2,3); // Khai báo tên Bluetooth và chân TX RX (2-TX, 3-RX)

char docgiatri; //Biến docgiatri kiểu char

void setup() 
{
  Serial.begin(9600);
  
  mybluetooth.begin(9600); //Kết nối Bluetooth với tốc độ baud là 9600

}

void loop() 
{
  if(mybluetooth.available() > 0) //Nếu tín hiệu của bluetooth lớn hơn 0, tức là đã kết nối OK
  {
    docgiatri = mybluetooth.read(); //Đọc các giá trị trên app được kết nối qua bluetooth và gán vào docgiatri
    Serial.println(docgiatri); //in giá trị lên cổng Serial
    Serial.println("");   
  }
}
