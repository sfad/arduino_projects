/*
   Board: Arduino UNO
   
   Poject Description: Muli-lines expmple code to I2C LCD. Two buttons used
   one for UP and the other for DOWN navigation throw the array of Strings "Lines".

   url: https://github.com/sfad/arduino_projects
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDRESS 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

#define BUTTON_DOWN 4
#define BUTTON_UP 5

const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

const byte LINES_SIZE = 9;
String lcdLines[LINES_SIZE] = {
   "LCD Line #1",
   "LCD Line #2",
   "LCD Line #3",
   "LCD Line #4",
   "LCD Line #5",
   "LCD Line #6",
   "LCD Line #7",
   "LCD Line #8",
   "LCD Line #9",
};
int columnIndex = 0;

void setup() 
{
   // LCD initialization
   lcd.backlight();
   lcd.init();
   lcd.setCursor(0,0);
   lcd.print(lcdLines[columnIndex]);
   lcd.setCursor(0,1);
   lcd.print(lcdLines[columnIndex + 1]);

   pinMode(BUTTON_DOWN, INPUT_PULLUP);
   pinMode(BUTTON_UP, INPUT_PULLUP);
}

void loop()
{
   delay(200); // samll delay for debounce
   if(digitalRead(BUTTON_DOWN) == LOW)
      moveLine("down");
   else if(digitalRead(BUTTON_UP) == LOW)
      moveLine("up");
}

void moveLine(String dir) {
   int line1Index=0, line2Index=0;
   if(dir == "down")
   {
      if(columnIndex >= LINES_SIZE - 2) return; // Reach end line so return;
      line1Index = ++columnIndex;
      line2Index = columnIndex + 1;
   }
   else if(dir == "up")
   {
      if(columnIndex <= 1) return; // Reach first line so return;
      line2Index = --columnIndex;
      line1Index = columnIndex - 1;
   }
   else
      return; // If not up or down do nothing and return.

   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print(lcdLines[line1Index]);
   lcd.setCursor(0,1);
   lcd.print(lcdLines[line2Index]);
}
