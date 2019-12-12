float Fugt() {
  // Wait a few seconds between measurements.
  // Vaerdierne måles hurtigt - ca 250 millisekunder
  // Sensoren kan kun maale hvert andet sekund ( der kan derfor ifølge guiden vaere en forsinkelse på det den læser.
  float fugt = dht.readHumidity();
  return fugt;
}

void fugtScroll() {

  scrollLine(0, 0, 18, messageF, 18);
  delay(500);
  Serial3.print( "Luftfugtighed: "); Serial3.println( Fugt());
  Serial1.print( "Luftfugtighed: "); Serial1.println( Fugt());
  
  tft.setCursor(0, 25);
  tft.print(Fugt()); tft.println(" %");
  tft.setCursor(0, 76);
  Alarm();
  // Short delay so the text doesn't move too fast
  delay(1500);
}
