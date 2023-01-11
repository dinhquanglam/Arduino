#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_TEMPLATE_ID "TMPLSSZCJUfA"
#define BLYNK_DEVICE_NAME "IoT Node 1"
#define BLYNK_AUTH_TOKEN "QP_bXRQPy8xLUfBIJF_GZRrZAyrmkZrJ"

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "QP_bXRQPy8xLUfBIJF_GZRrZAyrmkZrJ";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "QL iphone";
char pass[] = "Lam123123";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
