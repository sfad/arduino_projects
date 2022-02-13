/*
   Board: Arduino UNO
   
   Poject Description: Light sensor, the LED will be OFF during day time and
   when it get dark the light will turn ON.

   url: https://github.com/sfad/arduino_projects
*/

#define LED 6
#define THRESHOLD 300

void setup() {
   Serial.begin(9600);  //Initialize the terminal with 9600 baud rate
   pinMode(LED, OUTPUT);  //set PIN #9 as output
}

void loop() {
   int value = analogRead(A0);  //read analog from port A0 (10 bit)
   
   if(value > THRESHOLD) //is value > threshold const means day time
      digitalWrite(LED, LOW); // turn OFF the LED
   else
      digitalWrite(LED, HIGH); // turn ON the LED
   //Write data to terimal
   Serial.print("value = ");
   Serial.println(value);
   delay(500);    //wait 0.5 second (practically it's a good idea to increase the time)
                  // and use WDT.
}
