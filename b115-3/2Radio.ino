
const int pinSet  = 31;
const int pinAux  = 33;
const int pinEn   = 32;


void pinSetup()
{
  Serial.begin(9600);
  Serial3.begin(9600);
  pinMode(pinSet, OUTPUT);  //Setup (LOW)
  pinMode(pinAux, OUTPUT);  //
  pinMode(pinEn,  OUTPUT);  //Enable(HIGH)


  digitalWrite(pinSet, HIGH);
  digitalWrite(pinAux, HIGH);
  digitalWrite(pinEn,  HIGH);
}
