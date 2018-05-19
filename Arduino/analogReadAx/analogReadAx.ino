void setup() {  
//  analogReference(EXTERNAL);
  Serial.begin(250000);
  while(!Serial);
}

void loop() {
  Serial.println(analogRead(A3));
}
