float FoelesSom() {
  float foelesSom = dht.computeHeatIndex(Temp(), Fugt(), false); // beregner hvad temperaturen føles som ud fra fugt og temp
  return foelesSom;
}
void foelesSomScroll() {

  scrollLine(0, 0, 18, messageFS, 18);
  delay(500);
  Serial3.print( "Foeles som: "); Serial3.println( FoelesSom());
  Serial1.print( "Foeles som: "); Serial1.println( FoelesSom());

  tft.setCursor(0, 25);
  tft.print(FoelesSom());  tft.println("  C"); tft.drawCircle(75, 25, 2, ST7735_WHITE);
  tft.setCursor(0, 76);
  Alarm();

  // Short delay so the text doesn't move too fast
  delay(1500);
}
