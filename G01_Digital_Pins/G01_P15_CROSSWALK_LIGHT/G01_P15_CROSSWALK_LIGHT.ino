/*
   Board: Arduino UNO

   Poject Description: CROSSWALK Signal.

   url: https://github.com/sfad/arduino_projects
*/

#include <avr/wdt.h>

#define BUTTON_A 2
#define BUTTON_B 3

volatile bool switchAPressed = true;
volatile bool switchBPressed = true;

unsigned long lastMillis[2] = {0, 0};
byte indexSideA = 2;  //start A walk on 
byte indexSideB = 2;  //start B walk on

void setup()
{
  DDRB |= 0x3F; //set pins 0-6 of PORT B as OUTPUT
  DDRD |= 0xF0; //set pins 0-3 INPUT and 4-7 OUTPUT
  PORTD = 0x0C; //enable pullup on port 2 & 3

  PORTB = 0x24; //set red light of A & B ON
  PORTD |= 0xA0;  //crosswalk light both Red "Don't walk".
  attachInterrupt(digitalPinToInterrupt(BUTTON_A), switchA, FALLING);
  attachInterrupt(digitalPinToInterrupt(BUTTON_B), switchB, FALLING);

  // make a delay before enable WDT
  // this delay help to complete all initial tasks
  delay(1000);
  wdt_enable(WDTO_1S); //enable watch dog timer.
}

void loop() {
  if(switchAPressed) ButtonA_Pressed();
  if(switchBPressed) ButtonB_Pressed();
  //delay(2000);  //uncomment this line to test the WDT
  wdt_reset();  //reset watch dog timer.
}

void ButtonA_Pressed() {
  switch(indexSideA){
    case 0:
      greenA_OFF();
      yellowA_ON();
      if(AsyncWait('a', 1)) indexSideA++;
      break;
    case 1:
      yellowA_OFF();
      redA_ON();
      if(AsyncWait('a', 1)) indexSideA++;
      break;
    case 2:
      walkA_ON();
      //delay for crosswolker
      if(AsyncWait('a', 3)) indexSideA++;
      break;
    case 3:
      walkA_OFF();
      yellowA_ON();
      if(AsyncWait('a', 1)) indexSideA++;
      break;
    case 4:
      yellowA_OFF();
      redA_OFF();
      greenA_ON();
      if(AsyncWait('a', 1)) {
        indexSideA = 0;
        switchAPressed = false;
      }
      break;
    default:
      switchAPressed = false;
      indexSideA = 0;
      break;
  }
}

void ButtonB_Pressed() {
  switch(indexSideB){
    case 0:
      greenB_OFF();
      yellowB_ON();
      if(AsyncWait('b', 1)) indexSideB++;
      break;
    case 1:
      yellowB_OFF();
      redB_ON();
      if(AsyncWait('b', 1)) indexSideB++;
      break;
    case 2:
      walkB_ON();
      //delay for crosswolker
      if(AsyncWait('b', 3)) indexSideB++;
      break;
    case 3:
      walkB_OFF();
      yellowB_ON();
      if(AsyncWait('b', 1)) indexSideB++;
      break;
    case 4:
      yellowB_OFF();
      redB_OFF();
      greenB_ON();
      if(AsyncWait('b', 1)) {
        indexSideB = 0;
        switchBPressed = false;
      }
      break;
    default:
      switchBPressed = false;
      indexSideB = 0;
      break;
  }
}

bool AsyncWait(char side, unsigned int seconds) {
  bool reached = false;
  byte sideIndex = side == 'b' ? 1 : 0;
  if(lastMillis[sideIndex] == 0) {
    lastMillis[sideIndex] = millis();
  }

  if(millis() - lastMillis[sideIndex] < 0) {
    lastMillis[sideIndex] = (4294967295 - lastMillis[sideIndex]);
  }

  if( millis() - lastMillis[sideIndex] >= seconds * 1000) {
    reached = true;
    lastMillis[sideIndex] = 0;
  }

  return reached;
}

void switchA() {
  switchAPressed = true;
}

void switchB() {
  switchBPressed = true;
}

//SIDE A

void greenA_ON() {
  PORTB |= 1;
}

void greenA_OFF() {
  PORTB &= ~1;
}

void yellowA_ON() {
  PORTB |= 1 << 1;
}

void yellowA_OFF() {
  PORTB &= ~(1<<1);
}


void redA_ON() {
  PORTB |= 1 << 2;
}

void redA_OFF() {
  PORTB &= ~(1<<2);
}

void walkA_ON() {
  PORTD &= ~(1 << 7);
  PORTD |= 1 << 6;
}

void walkA_OFF() {
  PORTD |= 1 << 7;
  PORTD &= ~(1 << 6);
}

//SIDE B

void greenB_ON() {
  PORTB |= 1 << 3;
}

void greenB_OFF() {
  PORTB &= ~(1 << 3);
}

void yellowB_ON() {
  PORTB |= 1 << 4;
}

void yellowB_OFF() {
  PORTB &= ~(1<<4);
}


void redB_ON() {
  PORTB |= 1 << 5;
}

void redB_OFF() {
  PORTB &= ~(1<<5);
}

void walkB_ON() {
  PORTD &= ~(1 << 5);
  PORTD |= 1 << 4;  
}

void walkB_OFF() {
  PORTD |= 1 << 5;
  PORTD &= ~(1 << 4);
}
