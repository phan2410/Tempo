int PinOut = 22;
float DutyCycle = 0.5; //Max 1 = 100%
bool HighOrLow = LOW;
unsigned int Period = 100; //us
unsigned int HighTime = Period*DutyCycle;
unsigned int LowTime = Period - HighTime;
void setup() {
  // put your setup code here, to run once:
  pinMode(PinOut,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PinOut,HighOrLow);
  if (HighOrLow==HIGH) {
    delayMicroseconds(HighTime);
  } else {
    delayMicroseconds(LowTime);
  }
  HighOrLow = !HighOrLow;
}
