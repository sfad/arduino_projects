/*
   Board: Arduino UNO

   Poject Description: Demonstrate how to use switch statement.
   By putting all leds action in one project.

   url: https://github.com/sfad/arduino_projects
*/

#define DELAY_MS 300

void setup()
{
    Serial.begin(9600);
    DDRB = 0b00111111; // set pins 0-6 of PORT B as OUTPUT

    /*
       if analog input pin 0 is unconnected, random analog
       noise will cause the call to randomSeed() to generate
       different seed numbers each time the sketch runs.
       randomSeed() will then shuffle the random function.
    */
    randomSeed(analogRead(0));
}

void loop()
{
    int action = random(7);
    Serial.println(action);

    switch (action)
    {
    case 0:
        allOnOff();
        break;
    case 1:
        halfOnOff();
        break;
    case 2:
        movingLeft();
        break;
    case 3:
        movingRight();
        break;
    case 4:
        movingLeftRight();
        break;
    case 5:
        fillLeft();
        break;
    case 6:
        fillRight();
        break;
    default:
        wrongAction();
        break;
    }
}

void allOnOff()
{
    Serial.println("All ON OFF");
    PORTB = 0x3F;
    delay(DELAY_MS);
    PORTB = 0;
    delay(DELAY_MS);
}

void halfOnOff()
{
    Serial.println("HALF ON OFF");
    PORTB = 0x15;
    delay(DELAY_MS);
    PORTB = PORTB ^ 0x3F;
    delay(DELAY_MS);
    PORTB = 0;
}

void movingLeft()
{
    Serial.println("MOVING LEFT");
    digitalWrite(8, HIGH);
    delay(DELAY_MS);
    while (true)
    {
        PORTB = PORTB << 1;
        delay(DELAY_MS);
        if (PORTB == 0x20)
            break;
    }
    PORTB = 0;
}

void movingRight()
{
    Serial.println("MOVING RIGHT");
    digitalWrite(13, HIGH);
    delay(DELAY_MS);
    while (true)
    {
        PORTB = PORTB >> 1;
        delay(DELAY_MS);
        if (PORTB == 1)
            break;
    }
    PORTB = 0;
}

void movingLeftRight()
{
    Serial.println("MOVING LEFT RIGHT");
    movingLeft();
    movingRight();
}

void fillLeft()
{
    Serial.println("FILL LEFT");
    PORTB = 0;
    delay(DELAY_MS);
    while (true)
    {
        PORTB = PORTB << 1 | 1;
        delay(DELAY_MS);
        if (PORTB & 0x20)
            break;
    }
    while (true)
    {
        PORTB = PORTB >> 1;
        delay(DELAY_MS);
        if (PORTB == 0)
            break;
    }
}

void fillRight()
{
    Serial.println("FILL RIGHT");
    digitalWrite(13, HIGH);
    delay(DELAY_MS);
    while (true)
    {
        PORTB = PORTB >> 1 | 0x20;
        delay(DELAY_MS);
        if ((PORTB & 0x3F) == 0x3F)
            break;
    }
    while (true)
    {
        PORTB = PORTB << 1 & 0x3E;
        delay(DELAY_MS);
        if ((PORTB & 0x3F) == 0)
            break;
    }
}

void wrongAction()
{
    Serial.println("WRONG ACTION !!!!");
    delay(1000);
}
