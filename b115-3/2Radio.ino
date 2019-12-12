//Setup til radio
const int pinSet  = 31;    //Set sættes til pin 31
const int pinAux  = 33;    //AUX sættes til pin 31
const int pinEn   = 32;    //En sættes til pin 31

void pinSetup()
{
  Serial.begin(9600);
  Serial3.begin(9600);
  pinMode(pinSet, OUTPUT);      //Setup (LOW)
  pinMode(pinAux, OUTPUT);      // AUX (HIGH)
  pinMode(pinEn,  OUTPUT);      //Enable(HIGH)

  digitalWrite(pinSet, HIGH);   // Setup sættes høj
  digitalWrite(pinAux, HIGH);   // AUX sættes høj
  digitalWrite(pinEn,  HIGH);   // Enable sættes høj
}
