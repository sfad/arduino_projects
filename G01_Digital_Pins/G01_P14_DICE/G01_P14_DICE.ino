/*
   Board: Arduino UNO

   Poject Description: Dice game using 6 LEDs and a button.

   url: https://github.com/sfad/arduino_projects
*/

#define BUTTON 2
#define DELAY_MS 100

void setup()
{
    DDRB = 0b00111111; // set pins 0-6 of PORT B as OUTPUT
    pinMode(BUTTON, INPUT_PULLUP);

    /*
       if analog input pin 0 is unconnected, random analog
       noise will cause the call to randomSeed() to generate
       different seed numbers each time the sketch runs.
       randomSeed() will then shuffle the random function.
    */
    randomSeed(analogRead(0));
}

void loop() {
  if(digitalRead(BUTTON) == LOW) {
    startRotate();
    PORTB = rollDice();
  }
  delay(100);
}

//return bits base on random number 1-6
byte rollDice() {
    int action = random(1, 7);
    switch (action)
    {
      case 1:
        return 0b00000001;
      case 2:
        return 0b00100001;
      case 3:
        return 0b00100011;
      case 4:
        return 0b00110011;
      case 5:
        return 0b00110111;
      case 6:
        return 0b00111111;
      default:
        return 0;
    }
}

/*
  Move the leds five times before 
  each time you roll the dice.
*/
void startRotate()
{
    PORTB = 1;
    delay(DELAY_MS);
    int i = 0;
    while(i <= 5)
    {
        PORTB = PORTB << 1;
        delay(DELAY_MS);
        if (PORTB >= 0x20) {
          PORTB = 1;
          delay(DELAY_MS);
              i++;
        }
    }
}
