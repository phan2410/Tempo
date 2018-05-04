int mSec = 0;
int maxValue = 0;
void setup() {
  // put your setup code here, to run once:
  analogReference(EXTERNAL);
  analogRead(A0);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
//  if (sensorValue > maxValue)
//  {
//    maxValue = sensorValue;
//  }
//  if (sensorValue > 1000 && mSec == 0)
//  {
//    mSec = 1;
//  } else if (sensorValue > 80 && mSec > 0) {
//    mSec = mSec + 1;
//  } else if (sensorValue < 80 && mSec > 0)
//  {
//    Serial.println(mSec);
//  }
  Serial.println(sensorValue);
//  Serial.println(maxValue);
  delay(10);
}
