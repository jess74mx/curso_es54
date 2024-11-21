#include <Servo.h>

Servo cortinero;

const byte pinServo = 9;
byte giro = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);              
  //pinMode(4,OUTPUT);               
  Serial.begin(9600);
  cortinero.attach(pinServo);
  cortinero.write(90);
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  int valorLDR = analogRead(A0);                
  if( valorLDR <= 400 && giro <= 175) {
    for(giro = 5; giro <= 175; giro = giro + 5){
      Serial.println("Cerrando Persiana: " + String(giro));
      cortinero.write(giro);
      delay(1000);
    }
  } else if(valorLDR > 400 && giro >= 5){
    for(giro = 175; giro >= 5; giro = giro - 5){
      Serial.println("Abriendo Persiana: " + String(giro));
      cortinero.write(giro);
      delay(1000);
    }
  }
}
