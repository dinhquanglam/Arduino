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
#define BLYNK_TEMPLATE_ID "TMPLqSDIZPO6"
#define BLYNK_DEVICE_NAME "GAS sensor"
#define BLYNK_AUTH_TOKEN "wa0Rs4nLzeYXe3ppz27e0Mr6zNYRfXA-"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "wa0Rs4nLzeYXe3ppz27e0Mr6zNYRfXA-";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "AT";
char pass[] = "Dhirawatm170";

#define GAS_sensor A0       // Define the analog pin for GAS sensor
int rawValue;               // Declare a global variable for raw sensor data
int gasValue;               // Declare a global variable for converted Gas data


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
  
  pinMode(GAS_sensor, INPUT);     // Initialize the GAS_sensor pin as an input
  
  //Connecting to Blynk Cloud
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  
  // Reading raw sensor value from hardware analog pin A0
  rawValue = analogRead(GAS_sensor);
  gasValue = (rawValue*10000)/1023;
  Serial.print(gasValue);
  Serial.print("\n");
  Blynk.virtualWrite(V0, gasValue); 
  
}
