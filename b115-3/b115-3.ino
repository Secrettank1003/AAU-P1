#include "DHT.h" //DHT22
#include <virtuabotixRTC.h>

#include "SPI.h" // SPI display 
#include "Adafruit_GFX.h" // Adafruit graphics 
//#include "Adafruit_ILI9341.h" // ILI9341 screen controller

//#define sampletime 2000
//#define displaytime 4000

#define  anInput  A2                        //analog feed from MQ135
#define digTrigger   2                        //digital feed from MQ135
#define co2Zero     -11                       //calibrated CO2 0 level. ligger til derfor bliver plus lagt til og minus trækkes fra.
//Husk at værdierne går i mellem 0 og 1023 i mapning.
#define led          9                        //led on pin 9
#define Maal         10                       // antal målinger der fortages. 
#define graense        999                     //co2 grænse hvor der tændes en LED. 

#define DHTPIN 3     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

#include <Adafruit_ST7735.h>
#define TFT_DC 48 //TFT
#define TFT_CS 49 //TFT
#define TFT_RST 7 //TFT


unsigned long sampleT, dispT;
float p25;    // støv

DHT dht(DHTPIN, DHTTYPE);

//Wiring SCLK -> 6, I/O -> 7, CE -> 8 // ur
//Or CLK -> 6 , DAT -> 7, Reset -> 8  // ur
virtuabotixRTC myRTC(6, 7, 8);     // ur

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

/// \todo JDN alle strenge er 20 char lange ??
//                  01234567890123456789
char messageT[] =  "Temperatur:         ";
char messageF[] =  "Luftfugtighed:      ";
char messageFS[] = "Foeles som:         ";
char messageK[] =  "Klokken er:         ";
char messageS[] =  "Stoev niveau:       ";
char messageL[] =  "Lyd niveau:         ";
char messageC[] =  "CO2 niveau:         ";
const int width = 18;



void configDisplay()
{
  tft.initR(INITR_BLACKTAB);  //TFT
  tft.fillScreen(ST7735_BLACK);  //TFT
  tft.setTextColor(ST7735_WHITE, ST7735_BLACK);  // White on black
  tft.setTextWrap(false);  // Don't wrap text to next line
  tft.setTextSize(2);  // large letters
  tft.setRotation(1); // horizontal display
}

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);

  pinMode(4, INPUT); // stoej
  pinMode(anInput, INPUT);                    //MQ135 analog feed set for input
  pinMode(digTrigger, INPUT);                 //MQ135 digital feed set for input
  pinMode(led, OUTPUT);                       //led set for output

  dht.begin(); //DHT22

  configDisplay();

  //  sek  min  time ugedag dato  måned  år
  myRTC.setDS1302Time(00, 13, 13, 4, 12, 12, 2019);  // her skal man skrive de reelle tidspunkter

  //StoevRegistrer(); // da sensoren ikke er opkoblet, sidder den fadt i sit loop, derfor er den udkommenteret

  alarmInit();
  pinSetup(); //radio setup

  // JDN just bef gogo :-)
 
}

void scrollLine(int x, int y, int nrChOnDisplay, char *str, int lgt)
{
  for (int a = (nrChOnDisplay - 1); 0 <= a; a--) {
    tft.setCursor(x, y);
    // forst skrive blanke tegn der sletter
    for (int b = 0; b < a; b++) { // blanke forst med mellem rum
      tft.print(" "); // blanke ud
    }
    //nu skriver vi teksten
    for (int b = a; b < nrChOnDisplay; b++) {
      tft.print(*(str + (b - a))); // eller tft.print
    }
    /// \todo her skal delay ind for at sløve ned. Dvs delay mellem hver karakter
  }
}


void doSample() {

  Temp();
  Fugt();
  CO2();
  FoelesSom();
  Lyd();
  //Stoev();

}

void doDisplay() {
  tempScroll();
  tft.fillScreen(ST7735_BLACK);// for at cleare skærmen
  fugtScroll();
  tft.fillScreen(ST7735_BLACK);// for at cleare skærmen
  foelesSomScroll();
  tft.fillScreen(ST7735_BLACK); // for at cleare skærmen
  //stoevScroll();
  //tft.fillScreen(ST7735_BLACK);// for at cleare skærmen
  lydScroll();
  tft.fillScreen(ST7735_BLACK);// for at cleare skærmen
  CO2Scroll();
  tft.fillScreen(ST7735_BLACK);// for at cleare skærmen
  

}

int flag = 0;
void loop()
{
  doSample();
  doDisplay();
  

}
