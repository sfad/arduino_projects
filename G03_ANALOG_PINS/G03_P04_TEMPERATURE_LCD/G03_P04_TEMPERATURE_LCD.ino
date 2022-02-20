/*
        Board: Arduino UNO

        Poject Description: Measure temperature using LM35
                and output the result on LCD. Button Used to
                change the Temperature mode between C/F

        LCD I2C: https://github.com/johnrickman/LiquidCrystal_I2C

        url: https://github.com/sfad/arduino_projects
*/

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define BUTTON 2

LiquidCrystal_I2C lcd(0x27, 16, 2);  // run ic2_scanner sketch and get the IC2

char tempMode = 'c';

void setup() {
    lcd.backlight();
    lcd.init();                 // intialize the LCD
    lcd.setCursor(2, 0);        // set the cursor to Column 3, Row 1
    lcd.print("TEMPERATURE:");  // Print a message to the LCD.
    pinMode(BUTTON, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BUTTON), changeMode, FALLING);
}

void loop() {
    printTemp(tempMode);
    delay(1000);
}

void changeMode() { tempMode = tempMode == 'c' ? 'f' : 'c'; }

float getTemp(char mode) {
    int val = analogRead(A0);
    float mv = (val / 1023.0) * 5000;
    float cel = mv / 10;
    float fahr = (cel * 9) / 5 + 32;
    return mode == 'f' ? fahr : cel;
}

void printTemp(char mode) {
    clearLine2();
    lcd.setCursor(2, 1);  // set the cursor to Column 3, Row 2
    float temperature = getTemp(mode);
    lcd.print(temperature);
    lcd.print(mode == 'f' ? " F" : " C");
}

void clearLine2() {
    lcd.setCursor(2, 1);            // set the cursor to Column 3, Row 2
    lcd.print("                ");  // print 16 spaces to LCD
}