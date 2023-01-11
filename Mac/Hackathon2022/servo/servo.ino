int servoPin = 2;

void Movement(int);

void setup() {
// put your setup code here, to run once:
pinMode(servoPin,OUTPUT);
}

void loop() {
// put your main code here, to run repeatedly:
Movement(1);
delay(5000);
}

void Movement(int pos){
if (pos=1){
digitalWrite(servoPin,HIGH);
delay(2);
digitalWrite(servoPin,LOW);
delay(18);
}else{
digitalWrite(servoPin,HIGH);
delay(1);
digitalWrite(servoPin,LOW);
delay(19);
}
}
