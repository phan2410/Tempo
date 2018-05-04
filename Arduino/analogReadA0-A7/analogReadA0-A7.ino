int instantValues[8];

void readSensors() {
  instantValues[0] = analogRead(A0);
  instantValues[1] = analogRead(A1);
  instantValues[2] = analogRead(A2);
  instantValues[3] = analogRead(A3);
  instantValues[4] = analogRead(A4);
  instantValues[5] = analogRead(A5);
  instantValues[6] = analogRead(A6);
  instantValues[7] = analogRead(A7);
}

void showInstantValues() {
  for (int i = 0; i <= 7; i++) {
    Serial.println(instantValues[i]);
  }
}

void setup() {
  // put your setup code here, to run once:
  analogReference(EXTERNAL);
  readSensors();
  Serial.begin(115200);
}

void loop() {
  readSensors();
  showInstantValues();
  delay(10);
}
