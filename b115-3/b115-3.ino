// Gruppe B115

#include "SPI.h"                   // SPI display, bibliotek til TFT skærm
#include "Adafruit_GFX.h"          // Adafruit graphics, bibliotek til TFT skærm, med grafik
#include <Adafruit_ST7735.h>       // Adafruit graphics, bibliotek til TFT skærm, med grafik

#define TFT_DC 48                  //TFT setup af DC ( data til SPI)
#define TFT_CS 49                  //TFT setup af CS (slave select)
#define TFT_RST 7                  //TFT setup af reset
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);   //definition af pins på TFT-display

#define  anInput  A2               //analog input fra MQ-135 sættes til A2
#define digTrigger   2             //digital input from MQ-135
#define co2Zero     -11            //kalibrerede CO2 0 level.  Den er minus da den skal lægges til, til slut.
#define led          9             //led på pin 9
#define Maal         10            // antal målinger der fortages af MQ-135 
#define graense      999           //co2 grænse hvor en LED skal tændes

#define DHTPIN 3                   // digital pin til DHT sensor
#define DHTTYPE DHT22              // vælger at definere DHT22
#include <hpma115s0.h>             // bibliotek til støv sensoren
#include "DHT.h"                   // bibliotek til DHT sensoren
DHT dht(DHTPIN, DHTTYPE);          // definition af DHT

#include <virtuabotixRTC.h>        // bibliotek til ur
virtuabotixRTC myRTC(6, 7, 8);     // ur opsætning af pins, se "2opsaetning2


//                  01234567890123456789,    dette er blot en lineal så vi ved at de alle er lige lange
char messageT[] =  "Temperatur:         ";   // tekst streng der printes på TFT-display til hver måling
char messageF[] =  "Luftfugtighed:      ";
char messageFS[] = "Foeles som:         ";
char messageS[] =  "Stoevniveau:       ";
char messageL[] =  "Lydniveau:         ";
char messageC[] =  "CO2-niveau:         ";
const int width = 18;                       // bredden sættes til 18 karakter på TFT-displayet

void configDisplay()                        // TFT-display
{
  tft.initR(INITR_BLACKTAB);                // Initialiserer den baggrund på TFT
  tft.fillScreen(ST7735_BLACK);             // TFT-skærmen bliver helt sort
  tft.setTextColor(ST7735_WHITE, ST7735_BLACK);  // Sætter tekst-farevnt il at være hvid tekst på sort baggrund
  tft.setTextWrap(false);                   // Teksten skal ikke bindes til næste linje
  tft.setTextSize(2);                       // Tekst størrelse 2
  tft.setRotation(1);                       // Sætter display til horisontalt  display
}

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);                      // initialiserer TX1 og RX1
  Serial2.begin(9600);                      // initialiserer TX1 og RX1
  pinMode(4, INPUT);                        // støj-sensoreren sættes til pin 4
  pinMode(anInput, INPUT);                  // MQ-135 analog kanal sættes som input
  pinMode(digTrigger, INPUT);               // MQ-135 digital kanal sættes som input
  pinMode(led, OUTPUT);                     // led sættes som output
  dht.begin();                              //DHT22 initialiseres
  configDisplay();                          //Initialiserer TFT-display

  //  sek  min  time ugedag dato  måned  år
  myRTC.setDS1302Time(00, 13, 13, 4, 12, 12, 2019);  // her noteres de reelle tidspunkter batteriet sættes i uret

  //StoevRegistrer(); // da sensoren ikke er opkoblet, sidder den fadt i sit loop, derfor er den udkommenteret

  alarmInit();                            // Alamen initialisers fra tab "3Alarm"
  pinSetup();                             // Pin setup af radio
}

void scrollLine(int x, int y, int nrChOnDisplay, char *str, int lgt) // Opsætningen af vores scroll
{
  for (int a = (nrChOnDisplay - 1); 0 <= a; a--) {            // der fjernes et bogstav hver gang teksten flyttes mod venstre
    tft.setCursor(x, y);
                                                              // forst skrive blanke tegn der sletter
    for (int b = 0; b < a; b++) {                             // blanke forst med mellemrum
      tft.print(" ");                                         // blanke ud
    }
                                                              // Teksten skrives nu
    for (int b = a; b < nrChOnDisplay; b++) {
      tft.print(*(str + (b - a)));
    }
  }
}


void doSample() {   // der samles data ind fra lle vores værdier

  Temp();           // temperatur
  Fugt();           // Relativ luftfugtighed
  CO2();            // CO2-målinger
  FoelesSom();      // Beregner hvordan temperaturen føles iht fugt og temperatur
  Lyd();            // lyd-sensor
  //Stoev();        // støv sensoren - denne er udkommentert da sensoreren er gået i stykker og derfor ikke anvendes længere
}

void doDisplay() {
  tempScroll();                  // refererer til vores scroll for temperaturen
  tft.fillScreen(ST7735_BLACK);  // for at cleare skærmen
  fugtScroll();                  // refererer til vores scroll for relativ luftfugtighed
  tft.fillScreen(ST7735_BLACK);  // for at cleare skærmen)
  foelesSomScroll();             // refererer til vores scroll for værdien for Føles som(temperatur og luftfugtighed)
  tft.fillScreen(ST7735_BLACK);  // for at cleare skærmen
  //stoevScroll();               // refererer til vores scroll for støv
  //tft.fillScreen(ST7735_BLACK);// for at cleare skærmen
  lydScroll();                   // refererer til vores scroll for temperaturen
  tft.fillScreen(ST7735_BLACK);  // for at cleare skærmen
  CO2Scroll();                   // refererer til vores scroll for CO2
  tft.fillScreen(ST7735_BLACK);  // for at cleare skærmen


}

void loop()
{
  doSample();
  doDisplay();
}
