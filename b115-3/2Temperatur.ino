float Temp() {
  int val;
  int tempPin = A1;                       //definerer A1 som værende vores pin til LM35
  val = analogRead(tempPin);              //Læser temperaturen
  float mv = ( val / 1023.0) * 5000;      //mv = milli volt - denne laves for at få milivolt
  float temp = mv / 10;
  return temp;                            // den divideres med 10 da dette er LM35's skalarfaktor
}

void tempScroll() {

  scrollLine(0, 0, 18, messageT, 18);                       // printer "Temparatur:", refererer til char i main code
  delay(500);
  Serial3.print( "Temperatur: "); Serial3.println( Temp()); // printer værdien på radio
  Serial1.print( "Temperatur: "); Serial1.println( Temp()); // printer værdien på Open logger /SD kortet
  tft.setCursor(0, 25);                                     // placeringen af teksten på TFT
  tft.print(Temp());  tft.println("  C"); tft.drawCircle(75, 25, 2, ST7735_WHITE); // printer værdien af temperatur samt "° C" på TFT
  tft.setCursor(0, 76);                                     // placeringen af Alarm teksten vælges 
  Alarm();                                                  // kalder Alarm
  delay(1500);                                              // delay så teksten bevæger sig i 1500 milisekunder          
}
