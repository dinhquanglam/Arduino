#include <ESP8266WiFi.h>
#define LED D2

unsigned char led_status=0;
const char* ssid = "Lamcuong";
const char* password = "0963875959";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  Serial.print("CONNECTING TO");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(400);
    Serial.print("-");
  }
  Serial.println("");
  Serial.println("WIFI CONNECTED!");

  server.begin();
  Serial.println("MINI SERVER STARTS AT : ");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  Serial.println("CLIENT FOUND");
  while (! client.available())
  {
    delay (1);
  }
 
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
 
  if (req.indexOf("/lightoff") != -1)  {
    led_status=0;
    digitalWrite(LED, LOW);
    Serial.println("LED OFF");
  }
  else if(req.indexOf("/lighton") != -1)
  {
    led_status=1;
    digitalWrite(LED,HIGH);
    Serial.println("LED ON");
  }

// Return the response
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("Connection: close");
client.println("");

client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.println("<head>");
client.println("<title>IOT</title>");
client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
client.println("</head>");
client.println("<body style=\"height:100%;margin:0;background:#f6f6f6\">");
client.println("<div style=\"height:6%;text-align:center;padding:3px;background:#4caf50;color:white;\">");
client.println("<h3>IOT</h3>");
client.println("</div>");
client.println("<br/>");
if(led_status == 1)
client.println("<div style=\"color:#f57c00;text-align:center;font-size:20px;font-weight:bold;\">LIGHT ON</div>");
else
client.println("<div style=\"color:#f57c00;text-align:center;font-size:20px;font-weight:bold;\">LIGHT OFF</div>");

client.println("<div style=\"color:#212121;text-align:center;\">status</div>");
client.println("<br/>");
client.println("<br/>");
client.println("<div style=\"text-align:center;\">");
client.println("<a href=\"/lighton\"\" style=\"color:white;background:#607d8b;padding:10px;border-radius:10px;text-decoration: none;\">LIGHT ON </a>");
client.println("</div>");
client.println("<br/>");
client.println("<br/>");
client.println("<div style=\"text-align:center;\">");
client.println("<a href=\"/lightoff\"\" style=\"color:white;background:#607d8b;padding:10px;border-radius:10px;text-decoration: none;\">LIGHT OFF </a>");
client.println("</div>");
client.println("</body>");
client.println("</html>");


  delay(1);
  Serial.println("RESPONSE SENT");
  Serial.println("");

}
