/*
   Board: Arduino UNO

   Poject Description: Welcome project to explore I2C LCD.

   url: https://github.com/sfad/arduino_projects
*/

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // run ic2_scanner sketch and get the IC2

void setup() {
    lcd.backlight();
    lcd.init();            // intialize the LCD
    lcd.setCursor(2, 0);   // set the cursor to Column 3, Row 1
    lcd.print("Welcome");  // Print a message to the LCD.
    lcd.setCursor(2, 1);   // set the cursor to Column 3, Row 2
    lcd.print("LCD");      // Print a message to the LCD.
}

int i = 0;
void loop() {
    lcd.setCursor(10, 1);  // set the cursor to Column 11, Row 2
    lcd.print(i);          // print i
    i++;                   // increment i by 1
    delay(1000);           // wait 1 second
}
