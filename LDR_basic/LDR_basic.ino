const int pinLDR = A0;
const byte pinLed = 4;

void setup(){
  // put your setup code here, to run once:
  pinMode(pinLDR,INPUT);                 
  pinMode(pinLed,OUTPUT);               
  Serial.begin(9600);               
} 
 
void loop(){
  // put your main code here, to run repeatedly:
  int valorLDR = analogRead(pinLDR);                
     
    if( valorLDR <= 400 ) 
    {
      digitalWrite(pinLed, HIGH);
      Serial.print("LED ON ");
      Serial.println(valorLDR);
      delay(500);
    }
  
    else
    {
      digitalWrite(pinLed, LOW);
      Serial.println("LED OFF");
      Serial.println(valorLDR);
      delay(500);
    }
  } 