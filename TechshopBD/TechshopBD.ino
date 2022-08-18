#include <LiquidCrystal_SR.h>  
           
LiquidCrystal_SR lcd(12, 13, 8); //DATA CLOCK LATCH
int backlight = 7;

void setup() {  // Begin setup
  pinMode(backlight, OUTPUT);
  lcd.begin(16, 2);                // set up the LCD's number of columns and rows: 
  lcd.clear();                     // clear the screen
  lcd.setCursor(0, 0);             // put cursor at colon 0 and row 0
  lcd.print("SPI LCD Module  ");   // print a text
  lcd.setCursor(0, 1);             // put cursor at colon 0 and row 1
  lcd.print("   techshopbd   ");   // print a tex

   // LCD Backlight Control 
    for (int i=0; i<3; i++)
  {
    digitalWrite(backlight, HIGH); // LCD Backlight ON
    delay(1000);               
    digitalWrite(backlight, LOW);  // LCD Backlight OFF
    delay(1000);               
  }
  digitalWrite(backlight, HIGH);   // LCD Backlight ON
 }

void loop() {

}
