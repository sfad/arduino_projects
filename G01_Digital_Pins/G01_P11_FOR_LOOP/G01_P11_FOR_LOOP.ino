/*
   Board: Arduino UNO

   Poject Description: When PUSH BUTTON pressed the LEDs will be ON
   for 300ms then OFF for 300ms for ONLY seven times.

   url: https://github.com/sfad/arduino_projects
*/

#define BUTTON 2

void setup() {
    DDRB = 0b00111111;              // set pins 0-6 of PORT B as OUTPUT
    pinMode(BUTTON, INPUT_PULLUP);  // configure pin #2 with internal builtin
                                    // pullup resistor
}

void loop() {
    if (digitalRead(BUTTON) == LOW) {
        for (int i = 0; i < 7; i++) {
            PORTB = 0x3F;
            delay(300);
            PORTB = 0;
            delay(300);
        }
    }
}
