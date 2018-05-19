#include <ESP8266WiFi.h>
#define _DebugMode_ 0

const char* ssid = "Phan";
const char* password = "0868464963";
const char* ServerIP = "192.168.1.13";
const int listeningPortOfServer = 11247;
WiFiClient client;
bool isArduinoWorking = false;

void setup() {
  Serial.begin(250000);
  while (!Serial);//waiting for serial initialization
  delay(100);
#if _DebugMode_
  Serial.println("\n\n\n---------------------------------");
  Serial.print("Connecting to ");
  Serial.println(ssid);
#else
  Serial.write(54);
  Serial.write(9);
  Serial.write(99);
#endif
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
#if _DebugMode_
    Serial.print(".");
#endif
  }
#if _DebugMode_
  Serial.print("\nWiFi Connected With IP Address:");
  Serial.println(WiFi.localIP());
  Serial.print("Try communicating with ");
  Serial.println(ServerIP);
#else
  Serial.write(54);
  Serial.write(18);
  Serial.write(99);
#endif
  while (!client.connect(ServerIP, listeningPortOfServer)) {
    delay(500);
#if _DebugMode_
    Serial.print(".");
#endif    
  }
#if _DebugMode_
  Serial.println("Welcome To Smart Shoe Server !");
  Serial.flush();  
#else
  Serial.write(54);
  Serial.write(27);
  Serial.write(99);
  isArduinoWorking = true;
#endif
}

void loop() {  
  client.print('R' + Serial.readStringUntil('\r'));
  if (!client.connected()) {
    if (isArduinoWorking) {
  #if !_DebugMode_
      Serial.write(54);
      Serial.write(18);
      Serial.write(99);    
  #endif    
      Serial.flush();
      client.stop();
      isArduinoWorking = false;
      ESP.reset();
    }
  }
}

