//#include <LiquidCrystal_I2C.h>
// LiquidCrystal_I2C lcd(0x27,16,2);

// defines pins numbers
const int trigPin = D1;
const int echoPin = D2;



// defines variables
long duration;
float distance;
float capacity;
float deepOfWaste = 20;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

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

if (distance >= 560){
  distance = 0;
}
else if (distance > deepOfWaste && distance < 560){
  distance = deepOfWaste;
}


// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.print(distance);
Serial.println("cm");

// formula to count capacity : C = 100 - (safetyDistance/deepOfWaste).100%
capacity = 100 - (distance/deepOfWaste)*100;


Serial.print(capacity);
Serial.println("%");
delay(2000);

}
