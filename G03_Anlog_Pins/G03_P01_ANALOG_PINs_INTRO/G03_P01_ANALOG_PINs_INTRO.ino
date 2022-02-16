/*
   Board: Arduino UNO

   Poject Description: Testing analog read and write function. Read value from
   analog 10 bit resolution and write it back to one of PWM pin #6 as an
   example.

   Note: PWM Pins for Uno 3, 5, 6, 9, 10, 11

   url: https://github.com/sfad/arduino_projects
*/

#define LED 6

void setup() {
    Serial.begin(9600);    // Initialize the terminal with 9600 baud rate
    pinMode(LED, OUTPUT);  // set PIN #9 as output
}

void loop() {
    delay(100);                  // wait 200ms
    int value = analogRead(A0);  // read analog from port A0 (10 bit)
    int data = map(value, 0, 1023, 0, 255);  // convert it to (8 bit)
    analogWrite(LED, data);                  // write it back to PWM pin #9
    // Write data to terimal
    Serial.print("value = ");
    Serial.print(value);
    Serial.print(" data = ");
    Serial.println(data);
}
