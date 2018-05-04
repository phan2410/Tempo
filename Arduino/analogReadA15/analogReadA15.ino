int instantValue[10]={0,0,0,0,0,0,0,0,0,0};
int averageValue=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//  int sensorValue = analogRead(A15)-analogRead(A14);

//average filter
//  for (int i = 0 ; i < (sizeof(instantValue)/sizeof(instantValue[0])) ; i++) 
//  {
//    instantValue[i] = analogRead(A15);
//    delay(1);
//  }
//  averageValue = 0;
//  for (int i = 0 ; i < (sizeof(instantValue)/sizeof(instantValue[0])) ; i++) 
//  {
//    averageValue+=instantValue[i];
//  }
//  averageValue = averageValue/(sizeof(instantValue)/sizeof(instantValue[0]));
  averageValue = analogRead(A7);
  Serial.println(averageValue);
  delay(10);
}
