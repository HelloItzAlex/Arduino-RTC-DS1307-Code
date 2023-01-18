#include <RTClib.h>

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
  Serial.print(__TIME__);
  rtc.adjust(DateTime(__DATE__, __TIME__));
}
void loop () {
  DateTime i = rtc.now();
  Serial.print(i.second());
  delay(1000);
}
