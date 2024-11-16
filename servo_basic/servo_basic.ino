#include <Servo.h>

const byte pinServo = 9;
Servo cortinero;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  cortinero.attach(pinServo);
  //cortinero.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  int giro;
  for(giro = 5; giro <= 175; giro=giro+5){
    cortinero.write(giro);
    delay(200);  // 20 milisegundos es el valor mínimo
  }
  delay(2000);
  for(giro = 175; giro >= 5; giro=giro-5){
    cortinero.write(giro);
    delay(200);  // 20 milisegundos es el valor mínimo
  }
  delay(2000);  
}
