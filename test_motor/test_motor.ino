const int enbA = 5;
const int enbB = 3;

// Chân điều khiển của động cơ
const int IN1 = 4;  
const int IN2 = 6;    
const int IN3 = 7;    
const int IN4 = 8;  

//xác định một biến cho mỗi động cơ
int RightSpd = 255;
int LeftSpd = 255;
int lenSpd = 255; 
int xuongSpd = 255;

void setup() {
  // put your setup code here, to run once:
  pinMode(enbA, OUTPUT);
  pinMode(enbB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  
  // put your main code here, to run repeatedly:

   // lên
       analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW); 
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW); 
      digitalWrite(IN4, HIGH);

      delay(3000);
      //xuống
       analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

      delay(3000);
       //Trái
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
          digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

      //phải
      delay(3000);
       analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);     
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

      delay(3000);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
   

      

      

      
 
  
      

}
