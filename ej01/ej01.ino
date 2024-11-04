int num = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Bienvenidos al curso del ATMEGA328p");
  delay(100);   // Pausar por 100 milisegundos
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Valor: ");
  Serial.print(num);
  Serial.println();
  num = num + 1;
  delay(2000);
}
