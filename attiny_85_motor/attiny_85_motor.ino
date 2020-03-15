void setup() {                
  // initialize the digital pin as an output.
  pinMode(0, OUTPUT); // IN1
  pinMode(1, OUTPUT); // IN2
  pinMode(2, OUTPUT); // IN3
  pinMode(3, OUTPUT); // IN4  
}


void loop() {
  digitalWrite(0, HIGH);   
  digitalWrite(1, LOW);
  delay(1000);              
  digitalWrite(2, HIGH);   
  digitalWrite(3, LOW); 
  delay(1000);            
  digitalWrite(0, LOW);   
  digitalWrite(1, HIGH);
  delay(1000);              
  digitalWrite(2, LOW);   
  digitalWrite(3, HIGH); 
  delay(1000); 
}
