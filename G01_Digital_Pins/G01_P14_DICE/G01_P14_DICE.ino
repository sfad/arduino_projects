/*
   Board: Arduino UNO

   Poject Description: Dice game using 6 LEDs and a button.

   url: https://github.com/sfad/arduino_projects
*/

#define BUTTON 2
#define CENTER_LED 7
#define DELAY_MS 100

void setup() {
    DDRB = 0b00111111;  // set pins 0-6 of PORT B as OUTPUT
    pinMode(CENTER_LED, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);

    /*
      if analog input pin 0 is unconnected, random analog
      noise will cause the call to randomSeed() to generate
      different seed numbers each time the sketch runs.
      randomSeed() will then shuffle the random function.
    */
    randomSeed(analogRead(A0));
}

void loop() {
    if (digitalRead(BUTTON) == LOW) rollDice();
    delay(100);
}

// return bits base on random number 1-6
void rollDice() {
    PORTB = 0;
    digitalWrite(CENTER_LED, LOW);
    startRotate();
    int action = random(1, 7);
    switch (action) {
        case 1:
            digitalWrite(CENTER_LED, HIGH);
            PORTB = 0;
            break;
        case 2:
            PORTB = 0b00100100;
            break;
        case 3:
            digitalWrite(CENTER_LED, HIGH);
            PORTB = 0b00100100;
            break;
        case 4:
            PORTB = 0b00101101;
            break;
        case 5:
            digitalWrite(CENTER_LED, HIGH);
            PORTB = 0b00101101;
            break;
        case 6:
            PORTB = 0b00111111;
            break;
    }
}

/*
  Move the leds five times before
  each time you roll the dice.
*/
void startRotate() {
    PORTB = 1;
    delay(DELAY_MS);
    int i = 0;
    while (i <= 5) {
        PORTB = PORTB << 1;
        delay(DELAY_MS);
        if (PORTB >= 0x20) {
            PORTB = 1;
            delay(DELAY_MS);
            i++;
        }
    }
}
