void setup() {
  pinMode(0,OUTPUT);   
  pinMode(1,OUTPUT); 
  pinMode(2,OUTPUT); 
  pinMode(3,OUTPUT);
}

void loop() {
  for ( int i = 0; i <= 9; i++ ) {
    digitalWrite(0,i/1%2);
    digitalWrite(1,i/2%2);
    digitalWrite(2,i/4%2);
    digitalWrite(3,i/8%2);
    delay(1000);
  }
}
