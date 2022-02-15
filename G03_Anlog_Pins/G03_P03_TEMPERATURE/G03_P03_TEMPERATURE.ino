/*
   Board: Arduino UNO
   
   Poject Description: TEMPERATURE Sensor LM35.

   url: https://github.com/sfad/arduino_projects
*/

void setup() {
   Serial.begin(9600);  //Initialize the terminal with 9600 baud rate
}

void loop() {
  int val = analogRead(A0);
  float mv = (val/1024.0)*5000;

  Serial.print("TEMPRATURE = ");
  printTemp(mv, 'c');
  printTemp(mv, 'f');
  delay(1000);
}

void printTemp(float mv, char mode) {
  float cel = mv/10;
  float fahr = (cel*9)/5 + 32;
  Serial.print(mode=='f' ? fahr : cel);
  Serial.print(mode=='f' ? " F" : " C");
  Serial.println();
}
