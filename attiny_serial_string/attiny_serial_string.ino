#include <SoftwareSerial.h>
// ***
// *** Define the RX and TX pins. Choose any two
// *** pins that are unused. Try to avoid D0 (pin 5)
// *** and D2 (pin 7) if you plan to use I2C.
// ***
#define RX 3   // *** D3, Pin 2
#define TX 4   // *** D4, Pin 3

// ***
// *** Define the software based serial port. Using the
// *** name Serial so that code can be used on other
// *** platforms that support hardware based serial. On
// *** chips that support the hardware serial, just
// *** comment this line.
// ***
SoftwareSerial Serial(RX, TX);

String a;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  Serial.begin(9600); //Set BluetoothBee BaudRate to default baud rate 38400
  Serial.print("\r\n+STWMOD=0\r\n"); //set the bluetooth work in slave mode
  Serial.print("\r\n+STNA=Hackaton\r\n"); //set the bluetooth name as "HC-05"
  Serial.print("\r\n+STOAUT=1\r\n"); // Permit Paired device to connect me
  Serial.print("\r\n+STAUTO=0\r\n"); // Auto-connection should be forbidden here
  
  delay(2000); // This delay is required.
  //blueToothSerial.print("\r\n+INQ=1\r\n"); //make the slave bluetooth inquirable 
  Serial.print("bluetooth connected!\n");
  
  delay(2000); // This delay is required.
  Serial.flush();
}

void loop() {
  while(Serial.available()) {
    a = Serial.readString();// read the incoming data as string
    Serial.println("I GOT THIS:");
    Serial.println(a);
  }
}
