/*  
modified on Nov 22, 2020
Modified by MehranMaleki from Arduino Examples
Home
*/

#include <Wire.h>
#include <ds3231.h>
#include <LiquidCrystal_I2C.h> // Library for LCD

struct ts t; 
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4); // Change to (0x27,20,4) for 20x4 LCD.

  void setup() {
  Serial.begin(9600);
  Wire.begin();
  DS3231_init(DS3231_CONTROL_INTCN);
  lcd.init();
  lcd.backlight();

  
  /*----------------------------------------------------------------------------
  In order to synchronise your clock module, insert timetable values below !
  ----------------------------------------------------------------------------*/
  t.hour=1; 
  t.min=24;
  t.sec=05;
  t.mday=18;
  t.mon=8;
  t.year=2022;
 
  DS3231_set(t); 
}

void loop() {
  DS3231_get(&t);

  Serial.print("Date : ");
  Serial.print(t.mday);
  Serial.print("/");
  Serial.print(t.mon);
  Serial.print("/");
  Serial.print(t.year);
  Serial.print("\t Hour : ");
  Serial.print(t.hour);
  Serial.print(":");
  Serial.print(t.min);
  Serial.print(".");
  Serial.println(t.sec);

  lcd.setCursor(2, 0);
  lcd.print("Date : ");
  lcd.print(t.mday);
  lcd.print("/");
  lcd.print(t.mon);
  lcd.print("/");
  lcd.print(t.year);

  lcd.setCursor(2, 1);
  lcd.print("Hour : ");
  lcd.print(t.hour);
  lcd.print(":");
  lcd.print(t.min);
  lcd.print(":");
  lcd.print(t.sec);

  delay(1000);
}
