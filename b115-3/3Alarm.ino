
float alarmInit()
{
  pinMode(36, OUTPUT);                            // grøn LED
  pinMode(37, OUTPUT);                            //rød LED
}

float Alarm() {
  tft.println();
  if (CO2() > 3000) {                             // hvis CO2 er over eller lig med 3000 sker følgende kode
    digitalWrite(36, LOW);                        // grøn LED slukker
    digitalWrite(37, HIGH);                       // rød LED tænder
    tft.setTextColor(ST7735_RED, ST7735_BLACK);   // tekstfarven sættes til sort tekst på rød baggrund

    char text[] = "Forlad lokale   ";
    char text1[] = "!! Hoej CO2!!    ";
    tft.setTextColor(ST7735_WHITE, ST7735_RED);   // laver hvid skrift på rød baggrund
    scrollLine(0, 85, 18, text1, 18);             // placeringen af teksten på TFT
    tft.setTextColor(ST7735_RED, ST7735_BLACK);   // tekstfarven sættes til rød tekst på sort baggrund
    scrollLine(0, 105, 18, text, 18);             // placeringen af teksten på TFT
    delay(500);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK); // tekstfarven sættes til hvid tekst på sort baggrund

  }
  else if (CO2() >= 1000) {                       // hvis CO2 er over eller lig med 1000 sker følgende
    digitalWrite(36, LOW);                        // grøn LED slukker
    digitalWrite(37, HIGH);                       // rød LED tænder
    tft.setTextColor(ST7735_RED, ST7735_BLACK);   // tekstfarven sættes til rød tekst på sort baggrund
    char text[] = "Luft ud  ";
    char text1[] = "Hoej CO2   ";
    scrollLine(0, 85, 18, text1, 18);             // placeringen af teksten på TFT
    scrollLine(0, 105, 18, text, 18);             // placeringen af teksten på TFT
    delay(500);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK); // tekstfarven sættes til hvid tekst på sort baggrund

  }
  else if (Temp() >= 26) {                        // hvis temperaturen er højere eller lig med 26°C sker følgende
    digitalWrite(36, LOW);                        // grøn LED slukker
    digitalWrite(37, HIGH);                       // rød LED tænder
    tft.setTextColor(ST7735_RED, ST7735_BLACK);   // tekstfarven sættes til rød tekst på sort baggrund
    char text[] = "Aaben vinduet   ";
    char text1[] = "Hoej temp.     ";
    scrollLine(0, 85, 18, text1, 18);             // placeringen af teksten på TFT
    scrollLine(0, 105, 18, text, 18);             // placeringen af teksten på TFT
    delay(500);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK); // tekstfarven sættes til hvid tekst på sort baggrund

  }
  else if (Temp() <= 19) {                        // hvis temperaturen er lavere eller lig med 19°C sker følgende
    digitalWrite(36, LOW);                        // grøn LED slukker
    digitalWrite(37, HIGH);                       // rød LED tænder
    tft.setTextColor(ST7735_RED, ST7735_BLACK);   // tekstfarven sættes til rød tekst på sort baggrund
    char text[] = "Varm lokalet   ";
    char text1[] = "Lav temp.   ";
    scrollLine(0, 85, 18, text1, 18);             // placeringen af teksten på TFT
    scrollLine(0, 105, 18, text, 18);             // placeringen af teksten på TFT
    delay(500);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK); // tekstfarven sættes til hvid tekst på sort baggrund
  }
  else if (p25 > 25) {                            // hvis støvniveauet er højere end 25 µg/m3 sker følgende
    digitalWrite(36, LOW);                        // grøn LED slukker
    digitalWrite(37, HIGH);                       // rød LED tænder
    tft.setTextColor(ST7735_RED, ST7735_BLACK);   // tekstfarven sættes til rød tekst på sort baggrund
    char text[] = "Luft ud        ";
    char text1[] = "Meget stoev   ";
    scrollLine(0, 85, 18, text1, 18);             // placeringen af teksten på TFT
    scrollLine(0, 105, 18, text, 18);             // placeringen af teksten på TFT
    delay(500);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK); // tekstfarven sættes til hvid tekst på sort baggrund

  }
  else if (Fugt() > 60) {                         // hvis fugt er højere end 60 % sker følgende
    digitalWrite(36, LOW);                        // grøn LED slukker
    digitalWrite(37, HIGH);                       // rød LED tænder
    tft.setTextColor(ST7735_RED, ST7735_BLACK);   // tekstfarven sættes til rød tekst på sort baggrund

    char text[] = "Fugtigt rum    ";
    char text1[] = "Luft ud       ";
    scrollLine(0, 85, 18, text, 18);              // placeringen af teksten på TFT
    scrollLine(0, 105, 18, text1, 18);            // placeringen af teksten på TFT
    delay(500);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK); // tekstfarven sættes til hvid tekst på sort baggrund
  }
  else if (Fugt() < 40) {                         // hvis fugt er lavere end 40 % sker følgende
    digitalWrite(36, LOW);                        // grøn LED slukker
    digitalWrite(37, HIGH);                       // rød LED tænder
    tft.setTextColor(ST7735_RED, ST7735_BLACK);   // tekstfarven sættes til rød tekst på sort baggrund
    char text[] = "Lav fugt       ";
    char text1[] = "Luft ud       ";
    scrollLine(0, 85, 18, text, 18);              // placeringen af teksten på TFT
    scrollLine(0, 105, 18, text1, 18);            // placeringen af teksten på TFT
    delay(500);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK); // tekstfarven sættes til hvid tekst på sort baggrund
  }
  else {                                          // hvis ingen af de overstående kriterier er opfyldt skal følgende
    digitalWrite(36, HIGH);                       // grøn LED tænder
    digitalWrite(37, LOW);                        // rød LED slukker
    myRTC.updateTime();                           // uret opdaterer tiden
    tft.setCursor(0, 100);                        // placeringen af uret på TFT
    tft.print(myRTC.hours); tft.print(":"); tft.print(myRTC.minutes); tft.print(":"); tft.println(myRTC.seconds);  // der printes timer, minutter og sekunder (klokken)
  }
}
