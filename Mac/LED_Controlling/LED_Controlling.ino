/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID "TMPLSSZCJUfA"
#define BLYNK_DEVICE_NAME "IoT Node 1"
#define BLYNK_AUTH_TOKEN "QP_bXRQPy8xLUfBIJF_GZRrZAyrmkZrJ"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "QL iphone";
char pass[] = "Lam123123";

void setup()
{
  // Debug Wifi connection
  Serial.begin(115200);
  delay(10);
  Serial.print("Connecting to ");
  // Print the WiFi name
  Serial.println(ssid);
  // Establish the ESP8266 at station mode and connect it to the defined WiFi
  WiFi.begin(ssid, pass);
  // Print "..." if the ESP8266 has not connected to the defined WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print "WiFi connected" and the IP address of ESP8266
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  
  //Connecting to Blynk Cloud
  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V1)
{ 
  if(param.asInt() == 1)
  {
    // execute this code if the switch widget is now ON
    digitalWrite(LED_BUILTIN,HIGH);  // Set LED_BUILTIN HIGH
  }
  else
  {
    // execute this code if the switch widget is now OFF
    digitalWrite(LED_BUILTIN,LOW);  // Set LED_BUILTIN LOW    
  }
  }
void loop()
{
  Blynk.run();
}
