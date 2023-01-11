/* Arduino Security System with the Keypad and LCD 
 * Creator Mert KILIC - Mert Arduino Tutorial and Project
 * Please subscribe for support
 * Thanks
 */

#include <LiquidCrystal_I2C.h>
#include <Keypad.h> //include keypad library - first you must install library (library link in the video description)

#define redLED 10 //define the LED pins
#define greenLED 11

char* password ="1234"; //create a password
int pozisyon = 0; //keypad position

const byte rows = 4; //number of the keypad's rows and columns
const byte cols = 4;

char keyMap [rows] [cols] = { //define the cymbols on the buttons of the keypad

  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins [rows] = {8, 7, 6, 5}; //pins of the keypad
byte colPins [cols] = {4, 3, 2, 1};

Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, rows, cols);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
Serial.begin(115200);
Wire.begin(19,18);
lcd.init();
lcd.backlight();
  pinMode(redLED, OUTPUT);  //set the LED as an output
  pinMode(greenLED, OUTPUT);
  setLocked (true); //state of the password
}

void loop(){

  char whichKey = myKeypad.getKey(); //define which key is pressed with getKey

  lcd.setCursor(0, 0);
  lcd.print("    Welcome");
  lcd.setCursor(0, 1);
  lcd.print(" Enter Password");

  if(whichKey == '*' || whichKey == '#' || whichKey == 'A' ||       //define invalid keys
  whichKey == 'B' || whichKey == 'C' || whichKey == 'D'){

    pozisyon=0;
    setLocked (true);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Invalid Key!");
    delay(1000);
    lcd.clear();
  }
  if(whichKey == password [pozisyon]){

    pozisyon ++;
  }
  if(pozisyon == 4){
    setLocked (false);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("*** Verified ***");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Mert Arduino");
    lcd.setCursor(0, 1);
    lcd.print("Tutorial Project");
    delay(7000);
    lcd.clear();
  }
  delay(100);
}

void setLocked(int locked){
  if(locked){
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    }
    else{
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);
    }
  }
