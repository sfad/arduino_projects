/*
   Board: Arduino UNO
   
   Poject Description: Read digital input on PORT #2 if HIGH then
   TURN ON ALL LEDs of PORT B otherwise TURN them OFF.
*/

void setup() {
   DDRB = 0b00111111;    //set pins 0-6 of PORT B as OUTPUT
   pinMode(2, INPUT_PULLUP);    //set pins #2 as INPUT
}

void loop() {
   if(digitalRead(2) == LOW)
      PORTB = 0xFF;
   else
      PORTB = 0;
}
