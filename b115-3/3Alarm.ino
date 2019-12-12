
float alarmInit()
{
  pinMode(36, OUTPUT); // grøn LED
  pinMode(37, OUTPUT); //rød LED
}

float Alarm() {
  const int width = 18;  // width of the marquee display (in characters)

  tft.println();
  if (CO2() > 3000) {
    digitalWrite(36, LOW);
    digitalWrite(37, HIGH);
    tft.setTextColor(ST7735_RED, ST7735_BLACK);

    char text[] = "Forlad lokale   ";
    char text1[] = "!! Hoej CO2!!    ";
    tft.setTextColor(ST7735_WHITE, ST7735_RED); // LAVER HVID SKRIFT PÅ RØD BAGGRUND
    scrollLine(0, 85, 18, text1, 18); // ret 0,0 til den position du vil skrive på
    tft.setTextColor(ST7735_RED, ST7735_BLACK);
    scrollLine(0, 105, 18, text, 18); // ret 0,0 til den position du vil skrive på
    delay(500);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);

  }
  else if (CO2() >= 1000) {
    digitalWrite(36, LOW);
    digitalWrite(37, HIGH);
    tft.setTextColor(ST7735_RED, ST7735_BLACK);

    char text[] = "Luft ud  ";
    char text1[] = "Hoej CO2   ";
    scrollLine(0, 85, 18, text1, 18); // ret 0,0 til den position du vil skrive på
    scrollLine(0, 105, 18, text, 18); // ret 0,0 til den position du vil skrive på
    delay(500);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);

  }
  else if (Temp() >= 26) {
    //JDN pinMode(30, LOW);
    //JDN pinMode(31, HIGH);
    digitalWrite(36, LOW);
    digitalWrite(37, HIGH);
    tft.setTextColor(ST7735_RED, ST7735_BLACK);

    char text[] = "Aaben vinduet   ";
    char text1[] = "Hoej temp.     ";
    scrollLine(0, 85, 18, text1, 18); // ret 0,0 til den position du vil skrive på
    scrollLine(0, 105, 18, text, 18); // ret 0,0 til den position du vil skrive på
    delay(500);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
    tft.setTextSize(2);  // large letters

  }
  else if (Temp() <= 19) {
    //JDN pinMode(30, LOW);
    //JDN pinMode(31, HIGH);
    digitalWrite(36, LOW);
    digitalWrite(37, HIGH);
    tft.setTextColor(ST7735_RED, ST7735_BLACK);

    char text[] = "Varm lokalet   ";
    char text1[] = "Lav temp.   ";
    scrollLine(0, 85, 18, text1, 18); // ret 0,0 til den position du vil skrive på
    scrollLine(0, 105, 18, text, 18); // ret 0,0 til den position du vil skrive på
    delay(500);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
    tft.setTextSize(2);  // large letters

  }
  else if (p25 > 25) {
    digitalWrite(36, LOW);
    digitalWrite(37, HIGH);
    tft.setTextColor(ST7735_RED, ST7735_BLACK);

    char text[] = "Luft ud        ";
    char text1[] = "Meget stoev   ";
    scrollLine(0, 85, 18, text1, 18); // ret 0,0 til den position du vil skrive på
    scrollLine(0, 105, 18, text, 18); // ret 0,0 til den position du vil skrive på

    delay(500);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);

  }

  else if (Fugt() > 60) {
    digitalWrite(36, LOW);
    digitalWrite(37, HIGH);
    tft.setTextColor(ST7735_RED, ST7735_BLACK);

    char text[] = "Fugtigt rum    ";
    char text1[] = "Luft ud       ";
    scrollLine(0, 85, 18, text, 18); // ret 0,0 til den position du vil skrive på
    scrollLine(0, 105, 18, text1, 18); // ret 0,0 til den position du vil skrive på

    delay(500);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);

  }
else if (Fugt() < 40) {
    digitalWrite(36, LOW);
    digitalWrite(37, HIGH);
    tft.setTextColor(ST7735_RED, ST7735_BLACK);

    char text[] = "Lav fugt       ";
    char text1[] = "Luft ud       ";
    scrollLine(0, 85, 18, text, 18); // ret 0,0 til den position du vil skrive på
    scrollLine(0, 105, 18, text1, 18); // ret 0,0 til den position du vil skrive på

    delay(500);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);

  }
  else {
    digitalWrite(36, HIGH);
    digitalWrite(37, LOW);
    myRTC.updateTime();
    tft.setCursor(0, 100);
    tft.print(myRTC.hours); tft.print(":"); tft.print(myRTC.minutes); tft.print(":"); tft.println(myRTC.seconds);

  }
}
