// include the library code:
#include <LiquidCrystal.h>
#include "RTClib.h"
RTC_DS1307 rtc;

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
  lcd.begin(16, 2);
  lcd.clear();

  if (! rtc.begin()) 
  {
    lcd.print("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) 
  {
    lcd.print("RTC is NOT running!");
  }
  
    //rtc.adjust(DateTime(__DATE__, __TIME__));//auto update from computer time
}

void loop() 
{
  DateTime i = rtc.now();
  ///////////////////////////////////Month
  if(i.month() < 10){
    lcd.print("0"+String(i.month()));
  }
  else{
    lcd.print(i.month());
  }
  ///////////////////////////////////
  lcd.print("_");
  ///////////////////////////////////Day
  if(i.day() < 10){
    lcd.print("0"+String(i.day()));
  }
  else{
    lcd.print(i.day());
  }
  ///////////////////////////////////Year
  lcd.print("_" + String(i.year()) + "-");
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  ///////////////////////////////////Hour
  if(i.hour() < 10){
    lcd.print("0"+String(i.hour()));
  }
  else{
    lcd.print(i.hour());
  }
  ///////////////////////////////////
  lcd.print("_");
  ///////////////////////////////////Minute
  if(i.minute() < 10){
    lcd.print("0"+String(i.minute()));
  }
  else{
    lcd.print(i.minute());
  }
  ///////////////////////////////////
  lcd.print("_");
  ///////////////////////////////////Second
  if(i.second() < 10){
    lcd.print("0"+String(i.second()));
  }
  else{
    lcd.print(i.second());
  }
  lcd.print(".csv");
  lcd.setCursor(0, 0);
  delay(500);
}
