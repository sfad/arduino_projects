/*
   Board: Arduino UNO
   
   Poject Description: One LED ON at a time then
   wait 200ms then next one goes ON when it reach
   the last LED it back again.
*/

void setup() {
   DDRB = 0b00111111;    //set pins 0-6 of PORT B as OUTPUT
   digitalWrite(13, HIGH);  //set pin #13 to HIGH
   delay(200);    //wait for 200ms (0.2 second)
}

void loop() {
   PORTB = PORTB & 1 ? 0x20 : PORTB >> 1; //check if bit #1 of PORT B is HIGH let pin #13 HIGH otherwise shitf right one bit
   delay(200);    //wait for 200ms (0.2 second)
}
