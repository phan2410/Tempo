int pin = 2; 
volatile unsigned int pulse; 
const int pulses_per_litre = 450; 
 
void setup() 
{ 
Serial.begin(9600); 
 
pinMode(pin, INPUT); 
attachInterrupt(0, count_pulse, RISING); 
} 
 
void loop() 
{ 
pulse=0; 
interrupts(); 
delay(10); 
noInterrupts(); 

if (pulse>0){
  Serial.print("Pulses per second: ");
  Serial.println(pulse*100); 
}
} 
 
void count_pulse() 
{ 
pulse++; 
} 
