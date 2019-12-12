/* 
 Opsætning af de forskellige komponenter i produktet

Fugt
Pin 1(til venstre) skal saettes til +5V
Pin 2( i midten) til DHTPIN 3 - sat op i koden
Pin 3 (til højre) skal saettes i ground(GND)

Temp:
Venstreben sættes til 5 V
Midterste ben til A1 - sat op i koden
Hoejreben til GND


Ur:
VCC: 5 V
GND: til ground
CLK: Pin 6 - sat op i koden
DAT: Pin 7 - sat op i koden
RST: Pin 8 - sat op i koden

Wiring SCLK -> 6, I/O -> 7, CE -> 8 // ur
Or CLK -> 6 , DAT -> 7, Reset -> 8  // ur
virtuabotixRTC myRTC(6, 7, 8);     // ^indsættes i denne linje i main kode

Støv:
Pin (sort): GND
Pin(rød): 5 V
Pin (blå): A2 på vores Level Shifter
Pin (grøn): A1 på level Shifter

Level Shifter
GND: GND
VCCA: 3.3 V
VCCB: 5 V
B1: TX2
B2: RX2 

Lyd:
GND: GND
VCC: 5V
D0 = pin 4

Skærm:
RST: 1 KΩ -> reset pin
CS : 1 KΩ -> pin 49
D/C: 1 KΩ -> pin 48
Digital In: 1 KΩ -> pin 51
CLK: 1KΩ --> pin 52
VCC: 5 V
BL: 5V --> saettes sammen med VCC
GND: GND

CO2:
VCC: 5V
GND: GND
A0: Pin A2

Radio:
GND: GND
VCC: 5 V
EN: pin 32
RXD: TX3
TXD: RX3
AUX: pin 33
SET: pin 31

Openlogger:
GRN: ground
RXT: TX1
TXD: RX1
VCC: 5V
GND: ground
BLK: ground

*/
