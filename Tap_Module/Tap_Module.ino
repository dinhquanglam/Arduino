
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int led1 = 13;
//const int led2 = 11;
//const int led3 = 10;
//const int led4 = 9;
// the pin that the LED is attached to
// Variables will change:
int buttonCounter = 0;   
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
void setup() {
 // initialize the button pin as a input:
 pinMode(buttonPin, INPUT);
 // initialize the LED as an output:
 pinMode(led1, OUTPUT);
 //pinMode(led2,OUTPUT);
 //pinMode(led3,OUTPUT);
 //pinMode(led4,OUTPUT);
 // initialize serial communication:
 Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}
void loop() {
 buttonState = digitalRead(buttonPin);
 // compare the buttonState to its previous state
 if (buttonState != lastButtonState) {
   // if the state has changed, increment the counter
   if (buttonState == HIGH) {
     // if the current state is HIGH then the button
     // wend from off to on:
     buttonCounter++;
     lcd.setCursor(2,0);
     lcd.print(buttonCounter);
     Serial.println("on");
     Serial.print("number of button pushes:  ");
     Serial.println(buttonCounter);
   } 
   else {
     // if the current state is LOW then the button
     // wend from on to off:
     Serial.println("off"); 
   }
 }
 // save the current state as the last state, 
 //for next time through the loop
 lastButtonState = buttonState;
 // turns on the LED every four button pushes by 
 // checking the modulo of the button push counter.
 // the modulo function gives you the remainder of 
 // the division of two numbers:
 if (buttonCounter % 2 == 0) {
   digitalWrite(led1, HIGH);
   //digitalWrite(led2, HIGH);
   //digitalWrite(led3, HIGH);
   //digitalWrite(led4, HIGH);
 } else {
  digitalWrite(led1, LOW);
  //digitalWrite(led2, LOW);
  //digitalWrite(led3, LOW);
  //digitalWrite(led4, LOW);
 }
}
