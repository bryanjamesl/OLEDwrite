// This code works to write to the OLED, just hard coded.  From BH
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SSD1306AsciiAvrI2c.h>
#include <RTClib.h>  
#include <SPI.h>

RTC_DS1307 rtc;   
DateTime now;  

int pumpOnTime = 4 * 1000;                // pump runtime 
int pumpPin = 8;                          // pin to drive the pump 
SSD1306AsciiAvrI2c oled;                  // Initialize the oled, I2C 

void printData (int x, int y, String data)   // Write to display, loc and data 
{
  oled.setCursor(x, y);
  oled.print(data);
}

void runPump(int run) {
  digitalWrite (pumpPin, HIGH);
  printData (0, 6, "Pump On ");
  delay(run);
  digitalWrite (pumpPin, LOW);
  printData (0, 6, "Pump Off");
  printData(35, 1, String(now.minute()));
}

void setup() 
{
  Serial.begin(9600);
  oled.begin(&Adafruit128x64, 0x3C);      // start oled 64x128 0x3C(I2C address of the display)
  oled.setFont (TimesNewRoman16);         // font size/type
  oled.clear();
  oled.setCursor (0, 1);
  // oled.print("Curr. Time:           ");       // print header 
  // oled.setCursor (0, 4);
  oled.print("Last: ");
  oled.setCursor (0,3.5);
  oled.print("Next: ");  
}

void loop() {
  delay(1000);
  Serial.println("In void loop ");
  runPump(pumpOnTime);
  // 3 lines added below was to test adding the RTC to OLED code (needs more setup)
  delay(1000);
  Serial.println(String("hour:\t")+now.hour());
  Serial.println(String("min:\t")+now.minute());
  

}



// misc code 
// printData (40, 1, "Apr 22, 23");
//  printData (40, 4, "Jan 9, 23");
 // printData (40, 6, "Jan 16, 23");