#include <SoftwareSerial.h>

#define RX 3 
#define TX 4 

SoftwareSerial BTSerial(RX, TX);

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

void setup() {
  BTSerial.begin(9600);
  inputString.reserve(200);
}

void loop() {
  if (stringComplete) {
    BTSerial.println(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (BTSerial.available()) {
    // get the new byte:
    char inChar = (char)BTSerial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }

}  
