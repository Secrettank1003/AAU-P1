int soundPin = A0;  // den analog port fra KY-038 sættes til A0 
int sensorValue = 0;  //varibel til at gemme måling fra KY-038. 
int GND= A1; // ground til KY-038 er sat til A1. 
int Vcc=A2; // Vcc til KY-038 er tilslutte til A2 
 
void setup ()
{
  pinMode(GND, OUTPUT);     
digitalWrite(GND, LOW);  
// giver 0 volt til GND på KY-038. 
pinMode(Vcc, OUTPUT); 
digitalWrite(Vcc, HIGH); 
// giver 0 volt til Vcc på KY-038. 
Serial.begin (9600);
}
 
void loop ()
{
sensorValue = analogRead (soundPin); //måling fra KY-038 foretages
Serial.print(millis()*0.001); Serial.print("    "); Serial.println (sensorValue, DEC); 
//tidspunkt i sekunder og den målt værdi skrives ud på Serial Monitor. 
delay (1000); //pause på 1 sek. i mellem hver måling. 
}
