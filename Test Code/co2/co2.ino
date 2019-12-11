/*
   Carbon Dioxide Parts Per Million Meter
   CO2PPM

   learnelectronics
   26 MAR 2017

   www.youtube.com/c/learnelectronics
   arduino0169@gmail.com
*/

/*
   Atmospheric CO2 Level..............400ppm
   Average indoor co2.............350-450ppm
   Maxiumum acceptable co2...........1000ppm
   Dangerous co2 levels.............>2000ppm
   
*/

//Kode taget fra: https://www.youtube.com/watch?v=V1uOHOcVZrE
//---------------------------------------------------------------------------------------------------------------
//                                                  LIBRARIES
//---------------------------------------------------------------------------------------------------------------
//

//---------------------------------------------------------------------------------------------------------------
//                                                   DEFINES
//---------------------------------------------------------------------------------------------------------------
#define anInput     A0                        //analog feed from MQ135
#define digTrigger   2                        //digital feed from MQ135
#define co2Zero     -11                       //calibrated CO2 0 level. ligger til derfor bliver plus lagt til og minus trækkes fra.
//Husk at værdierne går i mellem 0 og 1023 i mapning. 
#define led          9                        //led on pin 9
#define Maal         10                       // antal målinger der fortages. 
#define graense        999                     //co2 grænse hvor der tændes en LED. 

//---------------------------------------------------------------------------------------------------------------
//                                                LIBRARY CALL
//---------------------------------------------------------------------------------------------------------------
//


//---------------------------------------------------------------------------------------------------------------
//                                                  SETUP
//---------------------------------------------------------------------------------------------------------------
void setup() {

  pinMode(anInput, INPUT);                    //MQ135 analog feed set for input
  pinMode(digTrigger, INPUT);                 //MQ135 digital feed set for input
  pinMode(led, OUTPUT);                       //led set for output
  Serial.begin(9600);                         //serial comms for debuging
}
//---------------------------------------------------------------------------------------------------------------
//                                               MAIN LOOP
//---------------------------------------------------------------------------------------------------------------
void loop() {

  int co2now[Maal];                               //int array for co2 readings
  int co2raw = 0;                               //int for raw value of co2
  int co2comp = 0;                              //int for compensated co2
  int co2ppm = 0;                               //int for calculated ppm
  int co2averag = 0;                            //int for averaging



  for (int x = 0; x < Maal; x++) {              //samplpe co2 10x over 2 seconds
    co2now[x] = analogRead(anInput);
    delay(200);
  }

  for (int x = 0; x < Maal; x++) {                //add samples together
    co2averag = co2averag + co2now[x];

  }
  co2raw = (co2averag / Maal);           //divide samples by 10
  co2comp = co2raw + co2Zero;                 //calibration (defintere højere op) definere 0 værdien. 
  co2ppm = map(co2comp, 0, 1023, 400, 5000);  //map value for atmospheric levels 
  // "sige" at værdien 0 er 400 ppm og at værdien 1023 er 5000 ppm


  Serial.println("CO2 Level:");               //print title
  Serial.print(co2ppm);                      //print co2 ppm
  Serial.println(" PPM");                    //print units
  Serial.println(" ");                       //printer tom linje 
 
