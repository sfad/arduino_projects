/*
   Board: Arduino UNO

   Poject Description: half leds goes ON wait 500ms
   then goes off and other half of the leds goes ON wait 500ms
   and keep repeating.

   url: https://github.com/sfad/arduino_projects
*/

void setup() {
    DDRB = 0b00111111;  // set pins 0-6 of PORT B as OUTPUT
    PORTB = 0b010101;   // set half of the pins 0-6 to HIGH
    delay(500);         // wait 500ms (0.5 second)
}

void loop() {
    PORTB = PORTB ^ 0x3F;  // bitwise XOR
    delay(500);            // wait 500ms (0.5 second)
}
