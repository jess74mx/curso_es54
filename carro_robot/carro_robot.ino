#include <SoftwareSerial.h>	// libreria que permite establecer pines digitales
				// para comunicacion serie

SoftwareSerial BT(10, 11); 	// pin 10 como RX, pin 11 como TX

const int IN1 = 9;          // Pin PWM conectado al controlador del motor
const int IN2 = 6;          // Pin PWM conectado al controlador del motor
const int IN3 = 5;          // Pin PWM conectado al controlador del motor
const int IN4 = 3;          // Pin PWM conectado al controlador del motor

unsigned long lapso;        // Variable que almacena en tiempo de espera para detener motores 

void setup(){
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

// Iniciamos en cero salidas a los motores
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  Serial.begin(9600);
  BT.begin(38400);		// comunicacion serie entre Arduino y el modulo a 38400 bps
  lapso = millis();
}

void loop(){
  if (BT.available()){
    Serial.println("Lapso " + String(millis()-lapso));
    String value = BT.readStringUntil('#');
    String button = value.substring(6,8);
    Serial.println(value);
    Serial.println("Button " + button);
    if(button == "4"){
      // vehículo avanza
      digitalWrite(IN1, HIGH); 
      digitalWrite(IN2, LOW);     
      digitalWrite(IN3, HIGH); 
      digitalWrite(IN4, LOW);
    } else if(button == "3"){
      // vehículo retrocede
      digitalWrite(IN1, LOW); 
      digitalWrite(IN2, HIGH);   
      digitalWrite(IN3, LOW); 
      digitalWrite(IN4, HIGH); 
    } else if(button == "2"){
      // vehícuo gira derecha
      digitalWrite(IN1, HIGH); 
      digitalWrite(IN2, LOW); 
      digitalWrite(IN3, LOW); 
      digitalWrite(IN4, LOW); 
    } else if(button == "1"){
      //vehículo gira izquierda
      digitalWrite(IN1, LOW); 
      digitalWrite(IN2, LOW); 
      digitalWrite(IN3, HIGH); 
      digitalWrite(IN4, LOW); 
    }  
    lapso = millis();
  }

  if(Serial.available()){
    BT.write(Serial.read());
  }
  if(millis()-lapso >200){
    apagarMotores();
  }
}

void apagarMotores(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}