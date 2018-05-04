int PinOut = 9;
int DutyCycle = 127; //Max 255
void setup() {
  // put your setup code here, to run once:
  pinMode(PinOut,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(PinOut,DutyCycle);
  delay(1);
}
