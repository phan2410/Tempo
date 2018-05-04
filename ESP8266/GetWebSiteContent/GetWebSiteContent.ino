// Import required libraries
#include <ESP8266WiFi.h>
// WiFi parameters
const char* ssid = "Phan";
const char* password = "0868464963";
// Host
const char* host = "192.168.1.16";
void setup() {
// Start Serial
Serial.begin(115200);
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
}
int value = 0;
void loop() {
Serial.print("Connecting to ");
Serial.println(host);
// Use WiFiClient class to create TCP connections
WiFiClient client;
const int httpPort = 4054;
if (!client.connect(host, httpPort)) {
Serial.println("connection failed");
return;
}
// This will send the request to the server
client.print(String("GET /") + " HTTP/1.1\r\n" +
"Host: " + host + "\r\n" +
"Connection: close\r\n\r\n");
delay(10);
// Read all the lines of the reply from server and print them to Serial
while(client.available()){
String line = client.readStringUntil( '\R' );
Serial.print(line);
}
Serial.println();
Serial.println("closing connection");
delay(5000);
}
