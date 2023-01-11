// Công tắc nghiêng được sử dụng cho các ứng dụng khác nhau, 
//chẳng hạn như báo hiệu vị trí của van, bảo vệ độ nghiêng tối đa 
//(ví dụ: bệ hoặc bệ trên không), thay thế cho bộ trao đổi thủy ngân, 
//để bảo vệ nghiêng và bảo vệ nghiêng.

const int ledPin = 13;//the led attach to

void setup()

{

pinMode(ledPin,OUTPUT);//initialize the ledPin as an output

pinMode(2,INPUT);//set pin2 as INPUT

digitalWrite(2, HIGH);//set pin2 as HIGH

}

/******************************************/

void loop()

{

int digitalVal = digitalRead(2);//Read the value of pin2

if(HIGH == digitalVal)//if tilt switch is not breakover

{

digitalWrite(ledPin,LOW);//turn the led off

}

else ////if tilt switch breakover

{

digitalWrite(ledPin,HIGH);//turn the led on

}

}
