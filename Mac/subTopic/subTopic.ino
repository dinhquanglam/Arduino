#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <Servo.h>     

 
const char* ssid = "LamCuong";
const char* password =  "0963875959";
const char* mqttServer = "171.244.173.204";
const int mqttPort = 1884;
const char* mqttUser = "admin";
const char* mqttPassword = "admin";

Servo myservo; 
int pos = 0;

WiFiClient espClient;
PubSubClient client(espClient);
 
void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
 
  Serial.print("Message:");

  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);  
  }
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(payload);
    const bool state = root["state"];
    Serial.println();
    Serial.println(state);
    
    if (state == true){
        for(pos = 0; pos < 180; pos += 1){ 
        myservo.write(pos);
        }
        Serial.println("open"); 
        delay(15);

    }
    else{
        for(pos = 180; pos>=1; pos-=1) {                           
        myservo.write(pos);
        }
        Serial.println("close");
        delay(15);
    }

  Serial.println();
  Serial.println("-----------------------");
 
}
 
void setup() {

  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP32Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }

  myservo.attach(D6);

 
  client.subscribe("wasteManagement/waste1/control");
 
}
 
void loop() {
  client.loop();
}
