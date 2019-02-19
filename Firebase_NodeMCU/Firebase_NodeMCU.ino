#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "  *****************  " //Enter your Project Host ID
#define FIREBASE_AUTH "  *****************  "// Enter Your Secret Key 
#define WIFI_SSID " ***********  "          // Initialize with the Router SSID
#define WIFI_PASSWORD " ************ "      // Input your Router's Password

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  // connect to wifi.
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

int n = 0;

void loop() {

//Latitude, Longitude, Altitude, Time, 
//Location of the Source and Destination
  
  while (Serial1.available() > 0) {
    float lat = Serial1.parseInt();
    float lon= Serial1.parseInt();
    float alt = Serial1.parseInt();
    float tim = Serial1.parseInt();
    
    if (Serial1.read() == '\n') 
    {
  // update value
  Firebase.setFloat("Latitude", lat);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(50);

  Firebase.setFloat("Longitude", lon);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(50);

  Firebase.setFloat("Altitude", alt);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(50);

  Firebase.setFloat("Time", tim);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(50);
  }
 } 
}
