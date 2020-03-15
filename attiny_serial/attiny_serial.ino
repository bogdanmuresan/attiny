#include <SoftwareSerial.h>

#define LED 0

#define RX 3
#define TX 4

SoftwareSerial Serial(RX, TX);

int delayTime = 80;

void setup() {
        Serial.begin(9600);
        pinMode(LED, OUTPUT);
        Serial.println("System is fucking operational.");
}

void loop() {
        digitalWrite(LED, HIGH);
        if (Serial.available() > 0) {
                delayTime = Serial.read();
                Serial.print("I received: ");
                Serial.println(delayTime);
        }
        delay(delayTime);
        digitalWrite(LED, LOW);
        delay(delayTime);
}
