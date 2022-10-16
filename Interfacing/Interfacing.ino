#include "RTClib.h"

RTC_DS1307 rtc;

void setup () 
{
  Serial.begin(9600);
  
  if (! rtc.begin()) 
  {
    Serial.print("Couldn't find RTC");
    while (1);
  }
  
  if (! rtc.isrunning()) 
  {
    Serial.print("RTC is NOT running!");
  }
  
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}
void loop () {
  DateTime i = rtc.now();
  ///////////////////////////////////Month
  if(i.month() < 10){
    Serial.print("0"+String(i.month()));
  }
  else{
    Serial.print(i.month());
  }
  ///////////////////////////////////
  Serial.print("_");
  ///////////////////////////////////Day
  if(i.day() < 10){
    Serial.print("0"+String(i.day()));
  }
  else{
    Serial.print(i.day());
  }
  ///////////////////////////////////Year
  Serial.print("_" + String(i.year()) + "-");
  ///////////////////////////////////Hour
  if(i.hour() < 10){
    Serial.print("0"+String(i.hour()));
  }
  else{
    Serial.print(i.hour());
  }
  ///////////////////////////////////
  Serial.print("_");
  ///////////////////////////////////Minute
  if(i.minute() < 10){
    Serial.print("0"+String(i.minute()));
  }
  else{
    Serial.print(i.minute());
  }
  ///////////////////////////////////
  Serial.print("_");
  ///////////////////////////////////Second
  if(i.second() < 10){
    Serial.print("0"+String(i.second()));
  }
  else{
    Serial.print(i.second());
  }
  
  Serial.println(".csv");
  delay(500);
}
