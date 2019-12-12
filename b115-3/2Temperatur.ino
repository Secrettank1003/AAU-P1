float Temp() {
  int val;
  int tempPin = A1;
  val = analogRead(tempPin);
  float mv = ( val / 1023.0) * 5000;       //mv = milli volt
  float temp = mv / 10;
  return temp;
}

void tempScroll() {

  scrollLine(0, 0, 18, messageT, 18);
  delay(500);
  Serial3.print( "Temperatur: "); Serial3.println( Temp());
  Serial1.print( "Temperatur: "); Serial1.println( Temp());

  tft.setCursor(0, 25);
  tft.print(Temp());  tft.println("  C"); tft.drawCircle(75, 25, 2, ST7735_WHITE);
  tft.setCursor(0, 76);
  Alarm();

  // Short delay so the text doesn't move too fast
  delay(1500);
}
