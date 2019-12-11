//Code borrowed from library example virtuabotixRTC_version1.

#include <virtuabotixRTC.h>

virtuabotixRTC myRTC(6, 7, 8);  //(CLK, DAT, RST)

void setup()
{
  Serial.begin(9600);
//    Set the current date, and time in the following format:
//                      seconds, minutes, hours, day of the week, day of the month, month, year
//  myRTC.setDS1302Time(03     , 17     , 11   , 3              , 03              , 12   , 2019); //  uncomment to set time!
}

void loop()
{
  myRTC.updateTime();
// Start printing elements as individuals
  Serial.print("Current Date / Time: ");
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print("  ");
  Serial.print(myRTC.hours);
  Serial.print(":");
  Serial.print(myRTC.minutes);
  Serial.print(":");
  Serial.println(myRTC.seconds);
//  Delay so the program doesn't print non-stop
  delay( 1000);
}
