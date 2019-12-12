int co2now[Maal];                             //int array for co2 målinger
int co2raw = 0;                               //int for rå værdier af co2
int co2comp = 0;                              //int for kompenseret co2
int co2ppm = 0;                               //int for bereget ppm
int co2averag = 0;                            //int for gennemsnitlig CO2

float CO2() {

  for (int x = 0; x < Maal; x++) {            //Måler CO2 10 x over 2 sekunder
    co2now[x] = analogRead(anInput);
  }
  co2averag = 0;
  for (int x = 0; x < Maal; x++) {            //Sætter målingerne sammen

    co2averag = co2averag + co2now[x];

  }
  co2raw = (co2averag / Maal);                //dividerer målingerne med 10
  co2comp = co2raw + co2Zero;                 //Kalibrerer (definieret højere op) definerer 0 værdien.
  co2ppm = map(co2comp, 0, 1023, 400, 5000);  //Værdierne for atmospheric levels
  return co2ppm;
                                              //værdien 0 er 400 ppm og værdien 1023 er 5000 ppm
}
void CO2Scroll() {

  scrollLine(0, 0, 18, messageC, 18);                      // printer "CO2 niveau:", refererer til char i main code
  delay(500);
  Serial3.print( "CO2 niveau: "); Serial3.println( CO2()); // printer værdien på radio
  Serial1.print( "CO2 niveau: "); Serial1.println( CO2()); // printer værdien på Open logger /SD kortet
  tft.setCursor(0, 25);                                    // placeringen af teksten på TFT
  tft.print(CO2()); tft.println(" PPM");                   // printer værdien af CO2 samt "ppm" på TFT
  tft.setCursor(0, 76);                                    // placeringen af Alarm teksten vælges 
  Alarm();                                                 // kalder Alarm
  delay(1500);                                             // delay så teksten bevæger sig i 1500 milisekunder          
}
