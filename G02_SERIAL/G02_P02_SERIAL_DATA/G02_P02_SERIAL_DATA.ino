/*
   Board: Arduino UNO

   Poject Description: Using serial communication with arduino.

   url: https://github.com/sfad/arduino_projects
*/

void setup() {
    Serial.begin(9600);
    Serial.println("Enter numbers from 0-9: ");
}

void loop() {
    while (Serial.available()) {
        char data = (char)Serial.read();

        if (data == '0')
            Serial.println("Zero");
        else if (data == '1')
            Serial.println("One");
        else if (data == '2')
            Serial.println("Two");
        else if (data == '3')
            Serial.println("Three");
        else if (data == '4')
            Serial.println("Four");
        else if (data == '5')
            Serial.println("Five");
        else if (data == '6')
            Serial.println("Six");
        else if (data == '7')
            Serial.println("Seven");
        else if (data == '8')
            Serial.println("Eight");
        else if (data == '9')
            Serial.println("Nine");
    }
}
