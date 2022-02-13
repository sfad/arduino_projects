/*
   Board: Arduino UNO
   
   Poject Description: all leds goes ON wait 500ms
   then goes off and wait 500ms

   url: https://github.com/sfad/arduino_projects
   
   Method #1
*/

void setup() {
   DDRB = 0b00111111;	//set pins 0-6 of PORT B as OUTPUT
}

void loop() {
   PORTB = 0b00111111;	//set pins 0-6 of PORT B to HIGH
   delay(500);		//wait 500ms (0.5 second)
   PORTB = 0;		//set pins 0-6 of PORT B to LOW
   delay(500);		//wait 500ms (0.5 second)
}
