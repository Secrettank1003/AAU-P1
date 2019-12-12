
float Lyd() {
  int temp = digitalRead(4);
}
void lydScroll() {
  scrollLine(0, 0, 18, messageL, 18);
  delay(500);
  Serial3.print( "Lyd niveau: "); Serial3.print( Lyd());

  if (digitalRead(4) == 1) {
    Serial3.println( "For Hoejt");
    Serial1.println( "For Hoejt");
    tft.setCursor(0, 25);
    tft.setTextColor(ST7735_RED, ST7735_BLACK);
    tft.println("For hoejt");
    tft.setCursor(0, 76);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
    Alarm();
    digitalWrite(36, LOW);
    digitalWrite(37, HIGH);
    delay(1500);
  }
  else {
    Serial3.println( "Passende");
    Serial1.println( "Passende");
    tft.setCursor(0, 25);
    tft.println("Passende");
    tft.setCursor(0, 76);
    Alarm();

    // Short delay so the text doesn't move too fast
    delay(1500);
  }
}
