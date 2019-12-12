int co2now[Maal];                               //int array for co2 readings
int co2raw = 0;                               //int for raw value of co2
int co2comp = 0;                              //int for compensated co2
int co2ppm = 0;                               //int for calculated ppm
int co2averag = 0;//int for averaging

float CO2() {

  for (int x = 0; x < Maal; x++) {              //samplpe co2 10x over 2 seconds
    co2now[x] = analogRead(anInput);
    //delay(200);
  }
  co2averag = 0;
  for (int x = 0; x < Maal; x++) {                //add samples together

    co2averag = co2averag + co2now[x];

  }
  co2raw = (co2averag / Maal);           //divide samples by 10
  co2comp = co2raw + co2Zero;                 //calibration (defintere højere op) definere 0 værdien.
  co2ppm = map(co2comp, 0, 1023, 400, 5000);  //map value for atmospheric levels
  return co2ppm;
  // "sige" at værdien 0 er 400 ppm og at værdien 1023 er 5000 ppm
}
void CO2Scroll() {

  scrollLine(0, 0, 18, messageC, 18);
  delay(500);
  Serial3.print( "CO2 niveau: "); Serial3.println( CO2());
  Serial1.print( "CO2 niveau: "); Serial1.println( CO2());

  tft.setCursor(0, 25);
  tft.print(CO2()); tft.println(" PPM");
  tft.setCursor(0, 76);
  Alarm();

  // Short delay so the text doesn't move too fast
  delay(1500);
}
