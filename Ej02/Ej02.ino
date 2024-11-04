const byte pinLed = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinLed,OUTPUT); 
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinLed,1);
  delay(5000);
  digitalWrite(pinLed,0);
  delay(1000);
 
}
