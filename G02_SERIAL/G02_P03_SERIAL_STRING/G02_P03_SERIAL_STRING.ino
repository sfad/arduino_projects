/*
   Board: Arduino UNO

   Poject Description: Reading and writing string to serial mointor.
      type string to serial mointor and hit send button.

   url: https://github.com/sfad/arduino_projects
*/

void setup() {
  Serial.begin(9600);
  Serial.println("Enter some text: ");
}

void loop() {
  String data = "";
  while(Serial.available()) {
    data = Serial.readString(); //read the incoming data as string
    Serial.print("You entered: ");
    Serial.println(data);       //print string to serial mointor
  }
}
