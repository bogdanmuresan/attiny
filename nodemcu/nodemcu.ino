int button = D5;
int windowState = HIGH;
int ledPin = 2; // GPIO16

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);
  pinMode(ledPin, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.println(button);
}

void loop() {
  // put your main code here, to run repeatedly:
  int newWindowState = digitalRead(button);

  if (newWindowState != windowState) {
    if (newWindowState == HIGH) {
      Serial.println("Window Opened");
      digitalWrite(ledPin, LOW);
    }
    else {
      Serial.println("Window Closed");
      digitalWrite(ledPin, HIGH);
    }
    windowState = newWindowState;
  }
}
