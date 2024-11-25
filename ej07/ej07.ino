/*
  Ejemplo del modulo controlador de motor L298N, para controlar el giro de un motor
  de corriente continua con caja reductora y rueda utilizando el ATMEGA328P

  Curso Esc. Sec. Tec. 54
*/

const byte IN1 = 2;			    // IN1 a pin digital 2
const byte IN2 = 4;			    // IN2 a pin digital 3
const byte ENA = 3;			    // ENA a pin digital 5
const byte IN3 = 7;			    // IN3 a pin digital 7
const byte IN4 = 8;			    // IN4 a pin digital 8
const byte ENB = 6;			    // ENA a pin digital 9

const byte vel = 95;

void setup(){
  pinMode(IN1, OUTPUT);		  // IN1 como salida	
  pinMode(IN2, OUTPUT);		  // IN2 como salida
  pinMode(ENA, OUTPUT);		  // ENA como salida
  pinMode(IN3, OUTPUT);		  // IN3 como salida
  pinMode(IN4, OUTPUT);		  // IN4 como salida
  pinMode(ENB, OUTPUT);		  // ENB como salida
  delay(5000);
}

void loop(){
  // Giro de motores en un sentido
  analogWrite(ENA, vel);	// ENA en alto habilita motor A
  digitalWrite(IN1, LOW);	// IN1 en cero logico
  digitalWrite(IN2, HIGH);	// IN2 en uno logico

  analogWrite(ENB, vel);	// ENB en alto habilita motor B
  digitalWrite(IN3, LOW);	// IN3 en cero logico
  digitalWrite(IN4, HIGH);	// IN4 en uno logico
  delay(3000);			// demora de 3 seg.

  // Detener motores
  digitalWrite(ENA, LOW);	// ENA en bajo deshabilita motor A
  digitalWrite(ENB, LOW);	// ENB en bajo deshabilita motor B
  delay(2000);			// demora de 2 seg.

  // Giro de motores en sentido contrario
  analogWrite(ENA, vel);	// ENA en alto habilita motor A
  digitalWrite(IN1, HIGH);	// IN1 en uno logico
  digitalWrite(IN2, LOW);	// IN2 en cero logico

  analogWrite(ENB, vel);	// ENB en alto habilita motor B
  digitalWrite(IN3, HIGH);	// IN3 en uno logico
  digitalWrite(IN4, LOW);	// IN4 en cero logico
  delay(3000);			// demora de 3 seg.

  // Detener motores
  digitalWrite(ENA, LOW);	// ENA en bajo deshabilita motor A
  digitalWrite(ENB, LOW);	// ENB en bajo deshabilita motor B
  delay(2000);			// demora de 2 seg.

}