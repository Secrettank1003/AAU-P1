float FoelesSom() {
  float foelesSom = dht.computeHeatIndex(Temp(), Fugt(), false); // beregner hvad temperaturen føles som ud fra fugt og temp
  return foelesSom;
}
void foelesSomScroll() {

  scrollLine(0, 0, 18, messageFS, 18);                           // printer "Foeles som:", refererer til char i main code
  delay(500);
  Serial3.print( "Foeles som: "); Serial3.println( FoelesSom()); // printer værdien på radio
  Serial1.print( "Foeles som: "); Serial1.println( FoelesSom()); // printer værdien på Open logger /SD kortet
  tft.setCursor(0, 25);                                          // placeringen af teksten på TFT
  tft.print(FoelesSom());  tft.println("  C"); tft.drawCircle(75, 25, 2, ST7735_WHITE);
  tft.setCursor(0, 76);                                          // placeringen af Alarm teksten vælges 
  Alarm();                                                       // kalder Alarm
  delay(1500);                                                   // delay så teksten bevæger sig i 1500 milisekunder          
}
