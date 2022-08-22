int bientroX = A0;
int bientroY = A1;
int nutnhan = 3;

int giatriX;
int giatriY;
int giatrinut;

void setup() 
{
  Serial.begin (9600);

  pinMode (bientroX, INPUT);
  pinMode (bientroY, INPUT);
  pinMode (nutnhan, INPUT_PULLUP);

}

void loop() 
{
  giatriX = analogRead(bientroX);
  giatriY = analogRead(bientroY);
  giatrinut = digitalRead(nutnhan);

  Serial.print ("Giá trị X: ");
  Serial.print (giatriX);
  Serial.print ("   ");
  Serial.print ("Giá trị Y: ");
  Serial.print (giatriY);
  Serial.print ("   ");
  Serial.print ("Giá trị nút nhấn: ");
  Serial.println (giatrinut);
  delay (500);

}
