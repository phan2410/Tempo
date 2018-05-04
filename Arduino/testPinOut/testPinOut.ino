int PinOut = 2;
bool HighOrLow = LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(PinOut,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PinOut,HighOrLow);
  delay(1000);
  HighOrLow = !HighOrLow;
}
