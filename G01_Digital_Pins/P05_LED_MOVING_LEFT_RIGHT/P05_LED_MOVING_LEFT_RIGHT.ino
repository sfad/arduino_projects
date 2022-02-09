/*
   Board: Arduino UNO
   
   Poject Description: One LED ON at a time then
   wait 200ms then next one goes ON when it reach
   the last LED move back to other direction.
*/

bool isLTR = true;  //initial state from Left to Right.

void setup() {
   DDRB = 0b00111111;   //set pins 0-6 of PORT B as OUTPUT
   digitalWrite(8, HIGH); //set pin #13 to HIGH
   delay(200);      //wait for 200ms (0.2 second)
}

void loop() {
   PORTB = isLTR ? PORTB << 1 : PORTB >> 1; //is LTR shift left if true otherwise shift right
   delay(200);    //wait for 200ms (0.2 second)
   isLTR = PORTB & 0x20 || PORTB & 1 ? !isLTR : isLTR;  //is reach either end switch direction or don't change
}
