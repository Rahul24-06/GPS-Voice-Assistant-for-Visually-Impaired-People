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

  while (Serial1.available() > 0) {
    float temp = Serial1.parseInt();
    float hum = Serial1.parseInt();
    float pressure = Serial1.parseInt();
    float alt = Serial1.parseInt();
    float mag = Serial1.parseInt();
    float light = Serial1.parseInt();
    int gas = Serial1.parseInt();

    if (Serial1.read() == '\n') 
    {
  // update value
  Firebase.setFloat("Temperature", temp);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(50);

  Firebase.setFloat("Humidity", hum);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(50);

  Firebase.setFloat("Pressure",pressure);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(50);

  Firebase.setFloat("Altitude",alt);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(50);
  
  Firebase.setFloat("Magnetometer", mag);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(50);

  Firebase.setFloat("Light", light);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(50);

  Firebase.setInt("Gas", gas);
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
