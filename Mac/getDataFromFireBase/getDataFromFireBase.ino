#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "random-data-31454-default-rtdb.firebaseio.com"  
#define FIREBASE_AUTH "XaRcsWqqQLi57r1nd5Dq1cy9xlswb0eLizuIZbe5"  
#define WIFI_SSID "Lamcuong"
#define WIFI_PASSWORD "0963875959"
void setup() {
 Serial.begin(9600); // Starts the serial communication
  randomSeed(analogRead(0));
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void loop() {
  String waste = "waste";
   float a = Firebase.getFloat (waste + "/wasteXuanThuy" + "/longtitde");
   float b = Firebase.getFloat (waste +"/wasteXuanThuy"+ "/latitde" );
   int c = Firebase.getInt (waste + "/wasteXuanThuy"+ "/capacity");

  Serial.println(a);
  Serial.println(b);
  Serial.println(c);
  

}
