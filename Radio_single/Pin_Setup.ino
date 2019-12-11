void pinSetup()
{
  Serial.begin(9600);
  radioSerial.begin(9600);
  pinMode(pinSet, OUTPUT);  //Setup (LOW)
  pinMode(pinAux, OUTPUT);  //Low to Recieve, High to Transmit
  pinMode(pinTxd, OUTPUT);  //Transmitter
  pinMode(pinRxd, INPUT);   //Reciever
  pinMode(pinEn,  OUTPUT);  //Enable(HIGH)
  pinMode(pinVcc, OUTPUT);  // 5V

  digitalWrite(pinSet, HIGH);
  digitalWrite(pinAux, HIGH);
  digitalWrite(pinTxd, HIGH);
  digitalWrite(pinRxd, LOW);
  digitalWrite(pinEn,  HIGH);
  digitalWrite(pinVcc, HIGH);
}
