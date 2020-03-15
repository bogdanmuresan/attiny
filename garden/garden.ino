void setup() {
  pinMode(A1,INPUT);
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);

  digitalWrite(0,HIGH);
  delay(100);
  digitalWrite(0,LOW);
  delay(100);
  digitalWrite(0,HIGH);
  delay(100);
  digitalWrite(0,LOW);
  delay(100);
  digitalWrite(0,HIGH);
  delay(100);
  digitalWrite(0,LOW);
  delay(100);
}

void loop() {
  int val = analogRead(A1);
  if(val >= 1000){
    digitalWrite(0,HIGH);
    delay(100);
  }
  if(val >= 950){
    digitalWrite(1,HIGH);
    delay(100);
  }else{
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
  }
  delay(100);
}


