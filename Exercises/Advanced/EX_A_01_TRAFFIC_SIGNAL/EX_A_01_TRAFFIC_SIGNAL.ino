/*
   Board: Arduino UNO

   Poject Description: TRAFFIC Signal.
    P0-P3 for traffic A
      P0 - RED
      P1 - YELLOW
      P2 - GREEN
      P3 - CAR DETECTOR SENSOR
    P4-P7 for traffic B
      P4 - RED
      P5 - YELLOW
      P6 - GREEN
      P7 - CAR DETECTOR SENSOR

   url: https://github.com/sfad/arduino_projects
*/

#include <PCF8574.h>  // https://github.com/xreef/PCF8574_library
#include <Wire.h>
#include <avr/wdt.h>

// Set i2c addresses
PCF8574 s1(0x20);
PCF8574 s2(0x21);
PCF8574 s3(0x22);
PCF8574 s4(0x23);

unsigned long lastMillis = 0;

void setup() {
    // uncomment to debug the code.
    // Serial.begin(9600);

    setGPIO(s1);
    setGPIO(s2);
    setGPIO(s3);
    setGPIO(s4);
    // make a delay before enable WDT
    // this delay help to complete all initial tasks
    delay(1000);
    wdt_enable(WDTO_2S);  // enable watch dog timer.
}

void loop() {
    wdt_reset();  // reset watch dog timer.

    // Your Code goes here.
}

void setGPIO(PCF8574 pcf8574) {
    for (int i = 0; i < 8; i++) {
        pcf8574.pinMode(i, (i + 1) % 4 ? OUTPUT : INPUT);
    }

    for (int i = 0; i < 8; i++) {
        if ((i + 1) % 4 == 0) continue;
        pcf8574.digitalWrite(
            i, (i == 0) || (i == 4) ? HIGH : LOW);  // trun ON only red lights.
    }
}

bool AsyncWait(unsigned int seconds) {
    bool reached = false;
    if (lastMillis == 0) {
        lastMillis = millis();
    }

    if (millis() - lastMillis < 0) {
        lastMillis = (4294967295 - lastMillis);
    }

    if (millis() - lastMillis >= seconds * 1000) {
        reached = true;
        lastMillis = 0;
    }

    return reached;
}
