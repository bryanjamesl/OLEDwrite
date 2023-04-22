// This code works to write to the OLED, just hard coded but works!

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SSD1306AsciiAvrI2c.h>


// long unsigned interval = 1000 * 20;       // set the value for the interval 
int pumpOnTime = 4 * 1000;
int pumpPin = 8;                          // pin to drive the pump 

SSD1306AsciiAvrI2c oled;                  // Initialize the oled, I2C 

void printData (int x, int y, String data)   // Write to display, loc and data 
{
  oled.setCursor(x, y);
  oled.print(data);
}

void runPump() {
  digitalWrite (pumpPin, HIGH);
  printData (0, 6, "Pump Running  ");
  digitalWrite (pumpPin, LOW);
  printData (0, 6, "Pump Off       ");
}

void setup() 
{
  oled.begin(&Adafruit128x64, 0x3C);      // start oled 64x128 0x3C(I2C address of the display)
  oled.setFont (TimesNewRoman16);         // font size/type
  oled.clear();
  oled.setCursor (0, 1);
  // oled.print("XCurr. Time:           ");       // print header 
  // oled.setCursor (0, 4);
  oled.print("Last run:           ");
  oled.setCursor (0,6);
  oled.print("Next run:           ");  
}

void loop() {

  Serial.println(" In void loop ");
  delay(1000);
  printData (40, 1, "Apr 22, 23");
  printData (40, 4, "Jan 9, 23");
  printData (40, 6, "Jan 16, 23");
  digitalWrite(pumpPin, HIGH);
  delay(pumpOnTime);
  digitalWrite(pumpPin, LOW);
  delay(1000);
  runPump();
  delay(1000);

}
