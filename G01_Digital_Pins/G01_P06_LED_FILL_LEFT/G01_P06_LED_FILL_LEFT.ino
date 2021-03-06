/*
   Board: Arduino UNO

   Poject Description: First LED at RIGHT ON wait 200ms then
   one after another goes ON when it reach
   the last LED they goes one after another OFF.

   url: https://github.com/sfad/arduino_projects
*/

bool forward = true;  // initial state from Left to Right.

void setup() {
    DDRB = 0b00111111;      // set pins 0-6 of PORT B as OUTPUT
    digitalWrite(8, HIGH);  // set pin #13 to HIGH
    delay(200);             // wait for 200ms (0.2 second)
}

void loop() {
    PORTB = forward ? PORTB << 1 | 1
                    : PORTB >> 1;  // is forward shift left and set the first
                                   // bit otherwise shift right.
    delay(200);                    // wait for 200ms (0.2 second)
    forward =
        PORTB == 0x3F || PORTB == 1
            ? !forward
            : forward;  // is reach either end switch direction or don't change
}
