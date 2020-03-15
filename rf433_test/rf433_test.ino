#include <Manchester.h>

/*
  Manchester Receiver for Attiny
  In this example receiver will receive one 16 bit number per
  transmittion to switch a relay on or off. 
  try different speeds using these constants, your maximum possible
  speed will depend on various factors like transmitter type, 
  distance,  microcontroller speed, ...

  MAN_300 0
  MAN_600 1
  MAN_1200 2
  MAN_2400 3
  MAN_4800 4
  MAN_9600 5
  MAN_19200 6
  MAN_38400 7
*/
#define RX_PIN 0 
#define LED 2
#define __AVR_Attinyx5__

void setup()
{
  man.setupReceive(RX_PIN, MAN_1200);
  man.beginReceive();
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  delay(100);
}
void loop() {
  digitalWrite(LED, LOW);
if (man.receiveComplete()) {
    uint16_t m = man.getMessage();
    // man.beginReceive(); //start listening for next message right
                        //after you retrieve the message
                        char str[80];

   int str_len = sprintf(str, "%d", m);
   if (strcmp(str, "2777")) {
       digitalWrite(LED, HIGH);
       delay(300);
   }
  man.beginReceive();
  
} 
}
