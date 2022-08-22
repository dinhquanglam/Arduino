# 1 "C:\\Users\\Admin\\Documents\\Arduino\\Receiver\\Receiver.ino"
// Created by Dinh Quang Lam
// Date: 18/05/2022
// K64_DA_CLC1_K64_UET
// Hand gesture robots
// Computer Interface Programming_ Dr.Pham Duy Hung

# 8 "C:\\Users\\Admin\\Documents\\Arduino\\Receiver\\Receiver.ino" 2
# 9 "C:\\Users\\Admin\\Documents\\Arduino\\Receiver\\Receiver.ino" 2
# 10 "C:\\Users\\Admin\\Documents\\Arduino\\Receiver\\Receiver.ino" 2

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


void setup(){
  Serial.begin(9600);
  radio.begin();
  radio.setAutoAck(1);
  radio.setDataRate(RF24_1MBPS); // Tốc độ dữ liệu
  radio.setChannel(10); // Đặt kênh
  radio.openReadingPipe(1,pipe);
  radio.startListening();
  //pinMode(led, OUTPUT);

  pinMode(enbA, 0x1);
  pinMode(enbB, 0x1);
  pinMode(IN1, 0x1);
  pinMode(IN2, 0x1);
  pinMode(IN3, 0x1);
  pinMode(IN4, 0x1);

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
      digitalWrite(IN1, 0x0);
      digitalWrite(IN2, 0x1);
      digitalWrite(IN3, 0x0);
      digitalWrite(IN4, 0x1);
      }

         if(data[0] < 310){
         Serial.println("đi xuống");
          analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, 0x1);
      digitalWrite(IN2, 0x0);
      digitalWrite(IN3, 0x1);
      digitalWrite(IN4, 0x0);
         }


        if(data[1] > 180){
          Serial.println("rẽ phải");
             analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, 0x0);
      digitalWrite(IN2, 0x1);
      digitalWrite(IN3, 0x1);
      digitalWrite(IN4, 0x0);;
        }

         if(data[1] < 110){
          Serial.println("rẽ phải");
             analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, 0x0);
      digitalWrite(IN2, 0x1);
      digitalWrite(IN3, 0x1);
      digitalWrite(IN4, 0x0);

       Serial.println("rẽ trái");
         analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
          digitalWrite(IN1, 0x1);
      digitalWrite(IN2, 0x0);
      digitalWrite(IN3, 0x0);
      digitalWrite(IN4, 0x1);
         }

          if(data[0] > 330 && data[0] < 360 && data[1] > 130 && data[1] < 160){
            Serial.println("dừng");
            analogWrite(enbA, 0);
             analogWrite(enbB, 0); digitalWrite(IN1, 0x0);
  digitalWrite(IN1, 0x0);
      digitalWrite(IN2, 0x0);
      digitalWrite(IN3, 0x0);
      digitalWrite(IN4, 0x0);
         }


}
}
