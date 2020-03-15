#include <SoftwareSerial.h>

// Define the data transmit/receive pins in Arduino

#define TxD 0
#define RxD 1

SoftwareSerial mySerial(RxD, TxD); // RX, TX for Bluetooth

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

String myInputString = "";
bool myStringComplete = false;

void setup() {
  mySerial.begin(9600); // For Bluetooth
  Serial.begin(9600); // For the IDE monitor Tools -> Serial Monitor

  inputString.reserve(200);
  myInputString.reserve(200);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }

  // print the string when a newline arrives:
  if (myStringComplete) {
    mySerial.println(myInputString);
    // clear the string:
    myInputString = "";
    myStringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }

  while (mySerial.available()) {
    // get the new byte:
    char myChar = (char)mySerial.read();
    // add it to the inputString:
    myInputString += myChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (myChar == '\n') {
      myStringComplete = true;
    }
  }
}
