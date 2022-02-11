/*
   Board: Arduino UNO
   
   Poject Description: all leds goes ON wait 500ms
   then goes off and wait 500ms

   url: https://github.com/sfad/arduino_projects
   
   method #2
*/

void setup() {
   DDRB = 0b00111111;  //set pins 0-6 of PORT B as OUTPUT
   PORTB = 0b00111111;  //set pins 0-6 to HIGH
   delay(500);    //wait 500ms (0.5 second)
}

void loop() {
   PORTB = ~PORTB;  //bitwise complement (NOT)
   delay(500);    //wait 500ms (0.5 second)
}
