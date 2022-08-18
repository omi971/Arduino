#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f, 20, 4);

// variables for storing the time
//   second  minute  hour    weekday  date    month   year
byte ss=0,   mi=0,   hh=0,   wd=6,    dd=1,   mo=1,   yy=0;
 
void setup()
{
  delay(20); // maybe I don't really need this line
 
  Wire.begin();
 
  // clear /EOSC bit
  // Sometimes necessary to ensure that the clock
  // keeps running on just battery power. Once set,
  // it shouldn't need to be reset but it's a good
  // idea to make sure.
//  Wire.beginTransmission(0x68); // address DS3231
//  Wire.write(0x0E); // select register
//  Wire.write(0b00011100); // write register bitmap, bit 7 is /EOSC
//  Wire.endTransmission();

  delay(20); // maybe I don't really need this line either
 
  lcd.setBacklight(HIGH);
  lcd.clear();
 
  delay(20); // or this line, for that matter
}
 
void loop()
{
  // read the time from the RTC, if we can
  boolean gotTheTime = grabTime();
 
  if (gotTheTime) {
    // if we are here, then the time has been successfully read
    // and stored in global variables (ss, mi, hh, wd, dd, mo, yy)
    printTime(); 
  }
  else {
    // if we are here, then we tried to read the time but couldn't
    lcd.setCursor(0,0);
    lcd.print("Unable to read  ");
    lcd.setCursor(0,1);
    lcd.print("time from RTC.  ");
    //         01234567890123456
  }
 
  delay(100);
}


boolean grabTime() {
  // get time from the RTC and put it in global variables

  // send request to receive data starting at register 0
  Wire.beginTransmission(0x68); // 0x68 is DS3231 device address
  Wire.write((byte)0); // start at register 0
  Wire.endTransmission();
  Wire.requestFrom(0x68, 7); // request seven bytes (ss, mi, hh, wd, dd, mo, yy)
  // check for a reply from the RTC, and use it if we can
  if (Wire.available() >= 7) {
    // if we're here, we got a reply and it is long enough
    // so now we read the time
    ss = bcd2bin(Wire.read()); // get seconds
    mi = bcd2bin(Wire.read()); // get minutes
    hh = bcd2bin(Wire.read()); // get hours
    wd = bcd2bin(Wire.read()); // get day of week
    dd = bcd2bin(Wire.read()); // get day of month
    mo = bcd2bin(Wire.read()); // get month
    yy = bcd2bin(Wire.read()); // get year (two digits)
    // indicate that we successfully got the time
    return true;
  }
  else {
    // indicate that we were unable to read the time
    return false;
  }
}


byte bcd2bin(byte x) {
  // converts from binary-coded decimal to a "regular" binary number
  return ((((x >> 4) & 0xF) * 10) + (x & 0xF)) ;
}


void printTime() {
  // just like the name says 
  char buf[35]; // this is more than we really need, but so what?
  lcd.setCursor(0,0);
  //            0 12 3 45 6 78 9 0 1 23456
  sprintf(buf,"\'%02d.%02d.%02d(%c%c%c)  ",yy,mo,dd,
   "BSMTWTFS"[(wd<7)?wd:0],"auouehra"[(wd<7)?wd:0],"dnneduit"[(wd<7)?wd:0]);
  lcd.print(buf);
  lcd.setCursor(0,1);
  //            01 2 34 5 67 890123456
  sprintf(buf,"%02d:%02d:%02d        ",hh,mi,ss);
  lcd.print(buf);   
}
