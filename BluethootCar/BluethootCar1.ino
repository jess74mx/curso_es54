/*

 */
#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11);      // Definimos los pines RX y TX del Arduino conectados al Bluetooth 

const byte IN1 = 2;			    // IN1 a pin digital 2
const byte IN2 = 4;			    // IN2 a pin digital 3
const byte ENA = 3;			    // ENA a pin digital 5
const byte IN3 = 7;			    // IN3 a pin digital 7
const byte IN4 = 8;			    // IN4 a pin digital 8
const byte ENB = 6;			    // ENA a pin digital 9

const byte vel = 95;
unsigned long lapso;



void setup() {
  pinMode(IN1, OUTPUT);		  // IN1 como salida	
  pinMode(IN2, OUTPUT);		  // IN2 como salida
  pinMode(ENA, OUTPUT);		  // ENA como salida
  pinMode(IN3, OUTPUT);		  // IN3 como salida
  pinMode(IN4, OUTPUT);		  // IN4 como salida
  pinMode(ENB, OUTPUT);		  // ENB como salida
  Serial.begin(9600);
  BT.begin(38400);
  BT.println("Esperando comandos...");
  lapso = millis();
  delay(100);
}

void loop() { // run over and over
  if (BT.available()) {
    Serial.println("Lapso "+String(millis()-lapso));
    String value = BT.readStringUntil('#');
    String button = value.substring(6,8);
    Serial.println(value);
    Serial.println("Button: "+button);
    
    // Señales L298N
      if (button == "4"){
        // Avanzar
        analogWrite(ENA, vel);	// ENA en alto habilita motor A
        digitalWrite(IN1, LOW);	// IN1 en cero logico
        digitalWrite(IN2, HIGH);	// IN2 en uno logico
        analogWrite(ENB, vel);	// ENB en alto habilita motor B
        digitalWrite(IN3, LOW);	// IN3 en cero logico
        digitalWrite(IN4, HIGH);	// IN4 en uno logico
      } else if (button == "2"){
        // girar derecha
        analogWrite(ENA, vel);	// ENA en alto habilita motor A
        digitalWrite(IN1, LOW);	// IN1 en cero logico
        digitalWrite(IN2, HIGH);	// IN2 en uno logico
        analogWrite(ENB, 0);	// ENB en alto habilita motor B
      } else if (button == "3"){
        // Retroceder
        analogWrite(ENA, vel);	// ENA en alto habilita motor A
        digitalWrite(IN1, HIGH);	// IN1 en uno logico
        digitalWrite(IN2, LOW);	// IN2 en cero logico
        analogWrite(ENB, vel);	// ENB en alto habilita motor B
        digitalWrite(IN3, HIGH);	// IN3 en uno logico
        digitalWrite(IN4, LOW);	// IN4 en cero logico  
      } else if (button == "1"){
        // girar izquierda
        analogWrite(ENA, 0);	// ENA en alto habilita motor A
        analogWrite(ENB, vel);	// ENB en alto habilita motor B
        digitalWrite(IN3, LOW);	// IN3 en cero logico
        digitalWrite(IN4, HIGH);	// IN4 en uno logico
      }
      lapso = millis();
  }

  if (Serial.available()) {
    BT.write(Serial.read());
  }

  if (millis()-lapso > 200){
    apagarMotores();
  }
  
}

void apagarMotores(){
  digitalWrite(ENA, LOW);	// ENA en bajo deshabilita motor A
  digitalWrite(ENB, LOW);	// ENB en bajo deshabilita motor B
}
