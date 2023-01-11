// đọc giá trị Rotary Encoder
int phaA =A1;
int phaB=A2; 
int button=A3; int btnvalue;
int count =0; int present; int initial;
int src=11;


void setup() {
  // put your setup code here, to run once:
 
  Serial.begin(9600); // 9600bauds ., xung / giay

  pinMode(phaA,INPUT);
  pinMode(phaB,INPUT);
  pinMode(button,INPUT);
  pinMode(src,OUTPUT);

  initial = digitalRead(phaA);
}

void loop() {
  // put your main code here, to run repeatedly:
  
//  btnvalue = digitalRead(button);
//  Serial.print("Button:"); Serial.println(btnvalue);

  present = digitalRead(phaA);
  if(present != initial)
  {
    if(digitalRead(phaB) != present)
    {count ++;
  }
  else
  {
    count --;
  }
  Serial.print("present:");Serial.println(count);
  }
  initial = present;
// phần này chưa chạy đc. 
  if (present >= 100)
  {
    digitalWrite(src,HIGH);
  }
  else
  {digitalWrite(src,LOW);
  
}
  
 
//int phaA = 1;
//int phaB = 2;
//int nutnhan = 3; int gtnutnhan;
//
//int dem = 0; int hientai; int bandau; 
//  
//void setup() 
//{ 
//   Serial.begin (9600);
//   
//   pinMode(phaA,INPUT);
//   pinMode(phaB,INPUT);
//   pinMode(nutnhan, INPUT);
//      
//   bandau = digitalRead(phaA);   
//} 
//
//void loop() 
//{ 
//   gtnutnhan = digitalRead(nutnhan); 
//   Serial.print("Nút nhấn: "); Serial.println(gtnutnhan);
//   
//   hientai = digitalRead(phaA);   
//   if (hientai != bandau)
//   {     
//     if (digitalRead(phaB) != hientai) 
//     { 
//       dem ++;
//     } 
//     else 
//     {
//       dem --;
//     }
//     Serial.print("Giá trị: "); Serial.println(dem);
//   } 
//   bandau = hientai;
//}

//#include <Servo.h>
//Servo myservo;
//int servo = 8;
//int led = 9;
// 
//int phaA = 1;
//int phaB = 2;
//int nutnhan = 3; int gtnutnhan;
//
//int dem = 0; int hientai; int bandau; 
//  
//void setup() 
//{ 
//   Serial.begin (9600);
//
//   pinMode(led, OUTPUT);
//   myservo.attach(servo);
//   myservo.write(0);
//   
//   pinMode(phaA,INPUT);
//   pinMode(phaB,INPUT);
//   pinMode(nutnhan, INPUT);
//      
//   bandau = digitalRead(phaA);   
//} 
//
//void loop() 
//{ 
//   gtnutnhan = digitalRead(nutnhan); 
//   //Serial.print("Nút nhấn: "); Serial.println(gtnutnhan);
//   if (gtnutnhan == 0)
//   {
//    digitalWrite(led, HIGH);
//   }
//   else
//   {
//    digitalWrite(led, LOW);
//   }
//   
//   hientai = digitalRead(phaA);
//   
//   if (hientai != bandau)
//   {     
//     if (digitalRead(phaB) != hientai) 
//     { 
//       dem += 5;
//       if (dem >= 180)
//       {
//        dem = 180;
//       }
//     } 
//     else 
//     {
//       dem -=5;
//       if (dem <= 0)
//       {
//        dem = 0;
//       }       
//     }
//     myservo.write(dem);
//     Serial.print("Giá trị: "); Serial.println(dem);
//   } 
//   bandau = hientai;
//}
