
float Lyd() {
  int temp = digitalRead(4);                             // læser om lyd sensoreren reagerer på en høj lyd(over 80 dB(a)
}
void lydScroll() {
  scrollLine(0, 0, 18, messageL, 18);                    // printer "Lydniveau, refererer til char i main code
  delay(500);
  Serial3.print( "Lyd niveau: "); Serial3.print( Lyd()); // printer værdien på radio
  Serial1.print( "Lyd niveau: "); Serial1.print( Lyd()); // printer værdien på Open logger /SD kortet

  if (digitalRead(4) == 1) {                             // hvis der måles over 80 dB(a)
    Serial3.println( "For Hoejt");                       // printer værdien på radio
    Serial1.println( "For Hoejt");                       // printer værdien på Open logger /SD kortet
    tft.setCursor(0, 25);                                // placeringen af teksten på TFT
    tft.setTextColor(ST7735_RED, ST7735_BLACK);          // tekstfarven sættes til rød tekst på sort baggrund
    tft.println("For hoejt");                            // printer "For hoejt" på TFT
    tft.setCursor(0, 76);                                // placeringen af Alarm teksten vælges 
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);        // tekstfarven sættes igen til hvid tekst på sort baggrund
    Alarm();
    digitalWrite(36, LOW);                               // slukker den grønne LED
    digitalWrite(37, HIGH);                              // tænder den røde LED
    delay(1500);
  }
  else {
    Serial3.println( "Passende");                        // printer værdien på radio
    Serial1.println( "Passende");                        // printer værdien på Open logger /SD kortet
    tft.setCursor(0, 25);                                // placeringen af teksten på TFT
    tft.println("Passende");                             // printer "passende" på TFT
    tft.setCursor(0, 76);                                // placeringen af Alarm teksten vælges 
    Alarm();                                             // kalder Alarm
    delay(1500);                                         // delay så teksten bevæger sig i 1500 milisekunder          
  }
}
