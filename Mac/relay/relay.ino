int Relaypin= D3; // Define input pin for relay

void setup() {
  // put your setup code here, to run once:
pinMode(Relaypin, OUTPUT); // Define the Relaypin as output pin
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(Relaypin, LOW); // Sends high signal 
delay(3000); // Waits for 1 second
digitalWrite(Relaypin, HIGH); // Makes the signal low
delay(3000); // Waits for 1 second
}
