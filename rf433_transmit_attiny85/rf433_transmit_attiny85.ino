#include <Manchester.h>
/*
  Manchester Transmitter example
  Try different speeds using these constants, your maximum
  possible speed will depend on various factors like transmitter
  type, distance, microcontroller speed, ...
  MAN_300 0
  MAN_600 1
  MAN_1200 2
  MAN_2400 3
  MAN_4800 4
  MAN_9600 5
  MAN_19200 6
  MAN_38400 7
*/
#define TX_PIN 1      //pin where your transmitter is connected
#define __AVR_ATtiny85__

uint8_t transmit_data = 0;
uint8_t id = 5; //attiny ID

void setup() {
  //man.workAround1MhzTinyCore();
  man.setupTransmit(TX_PIN, MAN_2400);
}

void loop() {
  if (transmit_data == 255) transmit_data = 0;
  //man.transmit(transmit_data);
  //SENDER_ID can be ID of the sender if you have multiple transmitters so receiver knows who sent it
  //OR it can be receiver ID if you have multiple receivers so receiver knows it's for him
  //OR it can by just any arbitrary 4 bit number
  man.transmit(man.encodeMessage(id, transmit_data));
  transmit_data++;
  delay(10);
}
