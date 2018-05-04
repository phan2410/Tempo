// Import required libraries
#include <ESP8266WiFi.h>
// WiFi parameters
const char* ssid = "Phan";
const char* password = "0868464963";
// Host
const char* host = "192.168.1.11";
WiFiClient client;
const int httpPort = 11247;
void setup() {
// Start Serial
Serial.begin(250000);
delay(10);
// We start by connecting to a WiFi network
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
Serial.print("Connecting to ");
Serial.println(host);
// Use WiFiClient class to create TCP connections
  if (client.connect(host, httpPort)) {
    Serial.println("READY");
  } else {
    Serial.println("connection failed");
    return;
  }
  Serial.flush();
}

void loop() {
  client.print('R' + Serial.readStringUntil('\r'));
}

