/*
  Ejemplo del uso de entradas analógicas para recibir valor de un
  potenciometro y controlar la cantidad de luminocidad de un LED
  utilizando un puerto digital con PWM en el ATMEGA328P

  Curso Esc. Sec. Tec. 54
*/
int pinPot = A0;
const byte pinLed = 3;                        // el pin digital 3 soporta modulación por ancho de pulso

int valorPot;
int valorLed;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinPot, INPUT);
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  valorPot = analogRead(pinPot);
  valorLed = map(valorPot,0, 1023, 0, 255);   // la función map permite convertir el valor analógico (0-1023) a un valor digital PWM (0-255)
}
