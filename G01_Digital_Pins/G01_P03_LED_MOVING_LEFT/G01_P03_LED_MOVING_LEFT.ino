/*
   Board: Arduino UNO

   Poject Description: One LED ON at a time then
   wait 200ms then next one goes ON when it reach
   the last LED it back again.

   url: https://github.com/sfad/arduino_projects
*/

void setup() {
    DDRB = 0b00111111;      // set pins 0-6 of PORT B as OUTPUT
    digitalWrite(8, HIGH);  // set pin #8 to HIGH
    delay(200);             // wait for 200ms (0.2 second)
}

void loop() {
    PORTB = PORTB & 0x20
                ? 1
                : PORTB << 1;  // check if bit #6 of PORT B is HIGH let PORTB =
                               // 1 otherwise shitf left one bit
    delay(200);                // wait for 200ms (0.2 second)
}
