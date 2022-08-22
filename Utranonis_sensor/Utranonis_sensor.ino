#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 7;
const int ledPin = 13;

// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 5){
  tone(buzzer, 1000);
  digitalWrite(ledPin, HIGH);
  
}
else{
  noTone(buzzer);
  digitalWrite(ledPin, LOW);
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.print(distance);
Serial.println("cm");



lcd.init();
  lcd.backlight();
  lcd.setCursor(2,0); // dua con tro den 2->cot 3, 0->hang 1
  lcd.print("Mesurement"  );
  lcd.setCursor(0,1);
  lcd.print("Distance:");
  lcd.setCursor(10,1);
  lcd.print(distance);
  lcd.setCursor(12,1);
  lcd.print(" cm");
  
  
  
  
}
