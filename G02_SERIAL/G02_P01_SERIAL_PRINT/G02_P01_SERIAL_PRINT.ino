/*
   Board: Arduino UNO

   Poject Description: Using serial communication with arduino.

   url: https://github.com/sfad/arduino_projects
*/

void setup() {
    Serial.begin(9600);
    delay(100);
    int i = 0;
    while (i < 11) {
        Serial.print("number ");
        Serial.print(i);
        Serial.print(" is ");
        Serial.println(i % 2 ? "ODD" : "EVEN");
        i++;
    }
}

void loop() {}
