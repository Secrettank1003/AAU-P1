
bool my_status;               // støv
float p25;                    // støv
float p10;                    // støv
HPMA115S0 my_hpm(Serial2);    // støv


float Stoev() {
  my_status = my_hpm.read(&p25, &p10);                    //læsningen af p25 startes
}

void StoevRegistrer() {                                   // denne bruges primært til at teste om sensoreren virker
  Serial.println ("HPMA115S0 hardware serial example");
  my_status = my_hpm.stop_autosend();                     // stoper autosend
  if (my_status == 1) {                                   // denne tjekker at sensoreren registrerer partikler og dermed stopper autosend
    Serial.println("Autosend disabled");
  }
  else {
    Serial.print("Error1");                               // indikerer hvis initialiseringen fejler
  }
  my_status = my_hpm.start_measurement();                 // fanen startes og målingerne startes
  if (my_status == 1) {                                   // denne registrerer at partikel målingerne begynder
    Serial.println("Start Particle Measurement");
  }
  else {
    Serial.print("Error2");                               // indikerer hvis initialiseringen fejler
  }
}

void stoevScroll() {

  scrollLine(0, 0, 18, messageS, 18);                          // printer "Støvniveau, refererer til char i main code
  delay(500);
  Serial3.print( "Stoev niveau: "); Serial3.println( Stoev()); // printer værdien på radio
  Serial1.print( "Stoev niveau: "); Serial1.println( Stoev()); // printer værdien på Open logger /SD kortet
  tft.setCursor(0, 25);                                        // placeringen af teksten på TFT
  tft.print(p25); tft.println("µg/m3");                        // printer værdien af Støv samt "µg/m3" på TFT
  if (p25 < 25) {                                              // hvis værdien af støv er under 25 µg/m3
    tft.setCursor(0, 50);                                      // placeringen af teksten på TFT
    tft.println("Passende");                                   // Printer "passende" hvis støv er under 25 µg/m3
  }
  else if (p25 > 25) {                                         // hvis værdien af støv overstiger 25 µg/m3
    tft.setCursor(0, 50);                                      // placeringen af teksten på TFT
    tft.setTextColor(ST7735_RED, ST7735_BLACK);                // tekstfarven sættes til rød tekst på sort baggrund 
    tft.println("Hoejt");                                      // Printer "passende" hvis støv er over 25 µg/m3
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);              // tekstfarven sættes til hvid tekst på sort baggrund
  }
  tft.setCursor(0, 76);                                        // placeringen af Alarm teksten vælges 
  Alarm();                                                     // kalder Alarm
  delay(1500);                                                 // delay så teksten bevæger sig i 1500 milisekunder          
}
