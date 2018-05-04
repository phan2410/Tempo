void setup() {  
  analogReference(EXTERNAL);
  Serial.begin(115200);
  while(!Serial);
}

void loop() {
  Serial.println(analogRead(A8));
  delay(10);
}
