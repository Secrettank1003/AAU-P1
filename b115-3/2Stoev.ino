//#include <hpma115s0.h> //støv
#include <hpma115s0.h> //støv 
bool my_status; // støv

float p10;  // støv
HPMA115S0 my_hpm(Serial2); // støv


float Stoev() {
  my_status = my_hpm.read(&p25, &p10);
}

void StoevRegistrer() {
  Serial.println ("HPMA115S0 hardware serial example");
  //delay(100);
  // Stop autosend
  my_status = my_hpm.stop_autosend();
  if (my_status == 1) {
    Serial.println("Autosend disabled");
  }
  else {
    Serial.print("Error1");
  }

  // Start fan (and measurement mode)
  my_status = my_hpm.start_measurement();
  if (my_status == 1) {
    Serial.println("Start Particle Measurement");
  }
  else {
    Serial.print("Error2");
  }

}

void stoevScroll() {

  scrollLine(0, 0, 18, messageS, 18);
  delay(500);
  Serial3.print( "Stoev niveau: "); Serial3.println( Stoev());
  Serial1.print( "Stoev niveau: "); Serial1.println( Stoev());

  tft.setCursor(0, 25);
  tft.print(p25); tft.println("µg/m3");
  if (p25 < 25) {
    tft.setCursor(0, 50);

    tft.println("Passende");
  }
  else if (p25 > 25) {
    tft.setCursor(0, 50);
    tft.setTextColor(ST7735_RED, ST7735_BLACK);
    tft.println("Hoejt");
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
  }
  tft.setCursor(0, 76);
  Alarm();
  delay(1500);

}
