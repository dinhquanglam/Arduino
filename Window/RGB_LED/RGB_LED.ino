int redPin= 7;
int greenPin = 6;
int bluePin = 5;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  setColor(255, 0, 0); // Red Color
  Serial.println(" Color: RED");
  delay(1000);
  setColor(0, 255, 0); // Green Color
  Serial.println(" Color: GREEN ");
  delay(1000);
  setColor(0, 0, 255); // Blue Color
  Serial.println(" Color: BLUE");
  delay(1000);
  setColor(255, 255, 255); // White Color
  Serial.println(" Color: WHITE");
  delay(1000);
  setColor(170, 0, 255); // Purple Color
  Serial.println(" Color: Purple");
  delay(1000);
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
