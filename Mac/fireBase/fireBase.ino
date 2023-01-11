/*Before Building The Project You Can Simply Test 
The Firebase Database Functionality Using This Code*/

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>



float randNumber1;
float randNumber2;
float longtitude;
float latitude;


// wasteBin
const int trigPin = D1;
const int echoPin = D2;
long duration;
float distance;
int capacity;
float deepOfWaste = 20;
//////////


  //Trang Thi
  int   cap1 = 1;
  float long1 = 105.849195;
  float lat1 = 21.026644;
  //String state1 = "open";
  bool state1 = 'TRUE';

  //Phu Doan
  int   cap2 = 15; 
  float long2 = 105.847754;
  float lat2 =  21.029256;
  bool state2 = 'TRUE';
  
  // Nha Chung
  int   cap3 = 40;
  float long3 = 105.849870;
  float lat3 = 21.027996;
  bool state3 = 'TRUE';

  // Hang Trong
  int   cap4 = 85;
  float long4 = 105.850011;
  float lat4 =  21.029848;
  bool state4 = 'TRUE';

  // Le Thai To
  int   cap5 = 99;
  float long5 = 105.850973;
  float lat5 =  21.030799;
  bool state5 = 'TRUE';

  // Ly Quoc Su
  int   cap6 = 75;
  float long6 = 105.848855;
  float lat6 =  21.030513;
  bool state6 = 'TRUE';
  
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

  // wasteBin
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  //////////////
}

void loop() {

Serial.println("Sending_Data");

randNumber1 = random(180000000);
longtitude = randNumber1 / 1000000;
 
randNumber2 = random(180000000);
latitude = randNumber2 / 1000000;

 // wasteBin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

if (distance >= 560){
  distance = 0;
}
else if (distance > deepOfWaste && distance < 560){
  distance = deepOfWaste;
}
capacity = 100 - (distance/deepOfWaste)*100;



  Serial.print("Longtitute: ");
  Serial.println( longtitude);

  Serial.print("Lattitute: ");
  Serial.println( latitude);

  Serial.print("Capacity: ");
  Serial.print(capacity);
  Serial.println(" %");

  //////////////////////////////////
  if (cap1 > 100){
    cap1 = 0;
  }
   if (cap2 > 100){
    cap2 = 0;
  }
   if (cap3 > 100){
    cap3 = 0;
  }
   if (cap4 > 100){
    cap4 = 0;
  }
   if (cap5 > 100){
    cap5 = 0;
  }
  if (cap6 > 100){
    cap5 = 0;
  }
  String waste = "waste";
  
  // Waste in Xuan Thuy
  Firebase.setFloat (waste + "/waste1" + "/longtitde" ,long1);
  Firebase.setFloat (waste +"/waste1"+ "/latitde" ,lat1);
  Firebase.setInt (waste + "/waste1"+ "/capacity" ,cap1);
  Firebase.setBool (waste + "/waste1"+ "/state" ,state1);
  

  // Waste in Cau Giay
  Firebase.setFloat (waste + "/waste2" + "/longtitde" ,long2);
  Firebase.setFloat (waste +"/waste2"+ "/latitde" ,lat2);
  Firebase.setInt (waste + "/waste2"+ "/capacity" ,cap2);
  Firebase.setBool (waste + "/waste2"+ "/state" ,state2);
  
  // Waste in Duy Tan
  Firebase.setFloat (waste + "/waste3" + "/longtitde" ,long3);
  Firebase.setFloat (waste +"/waste3"+ "/latitde" ,lat3);
  Firebase.setInt (waste + "/waste3"+ "/capacity" ,cap3);
  Firebase.setBool (waste + "/waste3"+ "/state" ,state3);

  // Waste in Trung Kinh
  Firebase.setFloat (waste + "/waste4" + "/longtitde" ,long4);
  Firebase.setFloat (waste +"/waste4"+ "/latitde" ,lat4);
  Firebase.setInt (waste + "/waste4"+ "/capacity" ,cap4);
  Firebase.setBool (waste + "/waste4"+ "/state" ,state4);

  // Waste in Duong Lang
  Firebase.setFloat (waste + "/waste5" + "/longtitde" ,long5);
  Firebase.setFloat (waste +"/waste5"+ "/latitde" ,lat5);
  Firebase.setInt (waste + "/waste5"+ "/capacity" ,cap5);
  Firebase.setBool (waste + "/waste4"+ "/state" ,state4);

  Firebase.setFloat (waste + "/waste6" + "/longtitde" ,long6);
  Firebase.setFloat (waste +"/waste6"+ "/latitde" ,lat6);
  Firebase.setInt (waste + "/waste6"+ "/capacity" ,cap6);
  Firebase.setBool (waste + "/waste6"+ "/state" ,state6);

  float a =  Firebase.getFloat (waste +"/waste6"+ "/latitde");
Serial.println(a);


 /////////////////////////////
 // WasteControl
 String wasteControl = "wasteControl";
 Firebase.setBool (wasteControl + "/waste1"+ "/state" ,state1);
 Firebase.setBool (wasteControl + "/waste2"+ "/state" ,state2);
 Firebase.setBool (wasteControl + "/waste3"+ "/state" ,state3);
 Firebase.setBool (wasteControl + "/waste4"+ "/state" ,state4);
 Firebase.setBool (wasteControl + "/waste4"+ "/state" ,state4);
 Firebase.setBool (wasteControl + "/waste6"+ "/state" ,state6);
 

 
  delay(30000);

  cap1 +=10 ;
  cap2 +=7 ;
  cap3 +=3 ;
  cap4 +=2 ;
  cap5 +=1 ;
  cap6 +=1 ;
  


 if(Firebase.failed())
{
  Serial.println("Firebase log sending failed");
  Serial.println(Firebase.error());
  return;
}

}
