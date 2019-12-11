#include <SoftwareSerial.h>

const int pinSet  = 8;
const int pinAux  = 9;
const int pinTxd  = 11;
const int pinRxd  = 10;
const int pinEn   = 12;
const int pinVcc  = 13;

SoftwareSerial radioSerial = SoftwareSerial(pinRxd, pinTxd); //Setup Software serial

void setup() {
  // put your setup code here, to run once:
  pinSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Sender"); //Print in Arduino Serial port
radioSerial.println("Reciever");  //Print in Radio Serial port
  delay(1000);
}
