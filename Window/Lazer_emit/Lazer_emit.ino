int laser = 10;//define laser to pin 10

int button = A0;//define button to pin A0

int buttonVal; //define the val of button

void setup() {

 pinMode(laser, OUTPUT); //set laser as output

 pinMode(button, INPUT);// set button as input

 Serial.begin(9600); //start the serial communications at 9600 bauds

}

void loop() {
 
 

  buttonVal = analogRead(button); //define buttonVal to equal the value of the button
 

  if(buttonVal == 0 ){

    digitalWrite(laser, HIGH);//if the button is pressed turn on laser
 

  }

else{

  digitalWrite(laser, LOW);//if else dont turn on the laser

}

Serial.println(buttonVal); //serial print the button value

}

 
