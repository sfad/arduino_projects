/*
   Board: Arduino UNO
   
   Poject Description: Passcode for turning ON or OFF for ports of arduino 0 - 3
   When the right code entered it you will be ask to choose the port to change toggle
   when * pressed last entered digit will be deleted.
   when # pressed the code will be cleared to enter new one.

   url: https://github.com/sfad/arduino_projects
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

#define KEY_SIZE 4
#define LCD_ADDRESS 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

const String PASS_CODE = "4321";

const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns

char keys[ROWS][COLS] = // Define the Keymap
{
   {'1','2','3'},
   {'4','5','6'},
   {'7','8','9'},
   {'*','0','#'}
};

byte rowPins[ROWS] = { 7, 6, 5, 4 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 10, 9, 8 }; // Connect keypad COL0, COL1 and COL2 to these Arduino pins.

Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);// Create the Keypad
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS); // run ic2_scanner sketch and get the IC2

String code;  //string to store the passcode.
bool ledsStatus[4] = { LOW, LOW, LOW, LOW }; //LEDs initial status.

void setup() {
   lcd.backlight();
   lcd.init();
   lcd.setCursor(0, 0);     //set the cursor to Column 3, Row 1
   lcd.print("Enter Passcode:");  //print to LCD.
   DDRD = 0x0F;       //set ports from 0 - 3 as output
}

void loop() {
   char key = kpd.getKey();

   if(key) {  // makes sure a key is actually pressed
      if(key == '*')
        undoLastKey();
      else if(key == '#')
        clearCode();
      else
        saveKey(key);
      delay(200);
   }

   if(code.length() == KEY_SIZE) { // if the array index is equal to the number of expected chars, compare data to master
      if(code == PASS_CODE) {
         lcd.setCursor(0,1);
         lcd.print("Port 0-3: ");
         char action = 0;
         while(!action) {
            action = kpd.getKey();
            if(action == '0')
               toggleLED(0);
            else if(action == '1')
               toggleLED(1);
            else if(action == '2')
               toggleLED(2);
            else if(action == '3')
               toggleLED(3);
            else if(action) {
               lcd.setCursor(0, 1);
               lcd.print("ERROR: 0 - 3");
               delay(1000);
               break;
            }
         }
      }

      clearCode();
  }
}

void clearCode() {
   code = "";   //clear code 
   lcd.setCursor(0,1);  //set cursor to column 1 row 2
   lcd.print("               ");  //clear line 2 by writing spaces
}

void saveKey(char key) {
   byte index = code.length();
   code += key;   // store char into data array
   lcd.setCursor(index, 1); // move cursor to show each new char
   lcd.print('*');  // print char at said cursor
}

void undoLastKey() {
   byte index = code.length();
   code = index == 0 ? "" : code.substring(0, --index); //remove one char from string
   lcd.setCursor(index, 1); //back one column
   lcd.print(' ');    //clear last * from LCD.
}

void toggleLED(byte port) {
   if(port < 0 || port > 3) return;   //make sure PORT is 0 - 3
   ledsStatus[port] = !ledsStatus[port];  //invert saved state
   digitalWrite(port, ledsStatus[port]);  //apply new state to the port
}
