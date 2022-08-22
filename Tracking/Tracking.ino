int sensor =  2;
int buzzer = 3;
int red = 4;
int green = 5;
 
void setup() {
Serial.begin(9600);
pinMode(sensor,INPUT);
pinMode(buzzer,OUTPUT);
pinMode(green,OUTPUT);
pinMode(red,OUTPUT);
 
 
}
 
void loop() {
bool value = digitalRead(sensor);
Serial.println(value);
if(value == 0)
{
  tone(buzzer, HIGH);
    digitalWrite(green, HIGH);
      digitalWrite(red, HIGH);
 
}
else
{
   noTone(buzzer);
    digitalWrite(green, LOW);
      digitalWrite(red, LOW);
  }
}
