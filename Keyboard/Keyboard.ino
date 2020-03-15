#include "DigiKeyboard.h"
int buttonPin = 0;
int buttonState = 0; 

void setup() {
   pinMode(buttonPin, INPUT);
}

void loop() {
  DigiKeyboard.sendKeyStroke(0);
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    DigiKeyboard.println("batman");
    DigiKeyboard.delay(5000);
  }
}

