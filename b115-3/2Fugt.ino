

float Fugt() {
                          // Vaerdierne måles hurtigt - ca 250 millisekunder
                          // Sensoren kan kun maale hvert andet sekund ( der kan derfor ifølge guiden vaere en forsinkelse på det den læser.)
  float fugt = dht.readHumidity();                              // læser værdien af den relative luftfugtighed
  return fugt;
}
void fugtScroll() {

  scrollLine(0, 0, 18, messageF, 18);                           // printer "Luftfugtighed, refererer til char i main code
  delay(500);
  Serial3.print( "Luftfugtighed: "); Serial3.println( Fugt());  // printer værdien på radio
  Serial1.print( "Luftfugtighed: "); Serial1.println( Fugt());  // printer værdien på Open logger /SD kortet
  tft.setCursor(0, 25);                                         // placeringen af teksten på TFT
  tft.print(Fugt()); tft.println(" %");                         // printer værdien af fugt samt %-tegnet på TFT
  tft.setCursor(0, 76);                                         // placeringen af Alarm teksten vælges 
  Alarm();                                                      // kalder Alarm
  delay(1500);                                                  // delay så teksten bevæger sig i 1500 milisekunder                     
}
