
#include "DHT.h"

#define DHTPIN A0     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

float Fugt() {
  // Wait a few seconds between measurements.

  // Vaerdierne måles hurtigt - ca 250 millisekunder
  // Sensoren kan kun maale hvert andet sekund ( der kan derfor ifølge guiden vaere en forsinkelse på det den læser.

  // Pin 1(til venstre) skal saettes til +5V
  // Pin 2( i midten) til DHTPIN A0
  // Pin 3 (til højre) skal saettes i ground(GND)

  float fugt = dht.readHumidity();
  // Serial.print("Luftfugtighed: ");
  //Serial.print(fugt); Serial.println(" %");

  return fugt;
}

float Temp() {

  // venstreben sættes til 5 V
  // Midterste ben til A1
  // hoejreben til GND
  int val;
  int tempPin = A1;
  val = analogRead(tempPin);
  float mv = ( val / 1023.0) * 5000;       //mv = milli volt
  float temp = mv / 10;

  /*Serial.print("Temperatur = ");
    Serial.print(temp);
    Serial.print(" C°");
    Serial.println();*/
  return temp;
}

// Registrerer heat index i celsius (isFahreheit = false)
float FoelesSom() {
  float foelesSom = dht.computeHeatIndex(Temp(), Fugt(), false);
  /*Serial.print("Føles som: ");
    Serial.print(foelesSom); Serial.println(" °C ");*/
  return foelesSom;

}

void FejlTjek() {       //returnerer kun hvis noget fejler i laesningen

  if (isnan(Fugt()) || isnan(Temp())) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
}

void printAlt() {
  Serial.print("Luftfugtighed: ");
  Serial.print(Fugt()); Serial.println(" %");

  Serial.print("Temperatur = ");
  Serial.print(Temp());
  Serial.print(" C°");
  Serial.println();
  Serial.print("Føles som: ");
  Serial.print(FoelesSom()); Serial.println(" °C ");
  Serial.println("");

}
void loop() {
  Fugt();
  delay(1000);
  Temp();
  delay(1000);
  FoelesSom();
  FejlTjek();
  delay(1000);
  printAlt();
  delay(1000);
}
