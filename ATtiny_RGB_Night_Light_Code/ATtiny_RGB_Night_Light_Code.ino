// attiny85 RGB LED rainbow fade with LDR
//Adapted from code by Matt Jenkins' Instructable http://www.instructables.com/id/Color-Changing-Night-Light/
// Code modifications to Matt Jenkins' code by Ross Satchell 2013
const int redPin = 2;
const int grnPin = 4;
const int bluPin = 1;
int sensorPin = 3; // select the input pin for the ldr
unsigned int sensorValue = 0; // variable to store the value coming from the ldr
void setup()
{
  pinMode(redPin, OUTPUT);  // set up red pin as output
  pinMode(grnPin, OUTPUT);  // set up green pin as output
  pinMode(bluPin, OUTPUT);  // set up blue pin as output
  
}

void loop()
{
  cyantoblue();    //  cyan to blue
  bluetomagenta();  //  blue to magenta
  magentatored();    //  magenta to red
  redtoyellow();      //  red to yellow
  yellowtogreen();    //  yellow to green
  greentocyan();      //  green to cyan
}

/************************************************************
  Gap between ON value (400) and is to OFF value (650) is to
 prevent flickering due to minor light level fluctuations
 *************************************************************/

void cyantoblue() //  cyan to blue 
{

  for(byte i=1; i<255; i++) {
    sensorValue = analogRead(sensorPin);
    if (sensorValue<400)
    {
      digitalWrite(redPin, HIGH);
      digitalWrite(bluPin, LOW);
      // start with Green on, then fade out Green to become Blue
      byte on = i;
      byte off = 255-on;
      for( byte a=0; a<255; a++ ) {
        digitalWrite(grnPin, HIGH);
        delayMicroseconds(on);
        digitalWrite(grnPin, LOW);
        delayMicroseconds(off);
      }
    }
    
    
    else if(sensorValue>650) // set the LED OFF // lower number for on when darker or raise number for on when brighter
    {
      ledsOff();
    }
 }
}

void bluetomagenta() //blue to magenta
{

  for(byte i=1; i<255; i++) {
    sensorValue = analogRead(sensorPin);
    if (sensorValue<400)
    {
      digitalWrite(grnPin, HIGH);
      digitalWrite(bluPin, LOW);
      // fade out red
      byte on = 255-i;
      byte off = i;
      for( byte a=0; a<255; a++ ) {
        digitalWrite(redPin, HIGH);
        delayMicroseconds(on);
        digitalWrite(redPin, LOW);
        delayMicroseconds(off);
      }
    }
  else if (sensorValue>650){ // set the LED OFF // lower number for on when darker or raise number for on when brighter
      ledsOff();
    }
 }
}

void magentatored() // magenta to red
{

  for(byte i=1; i<255; i++) {
    sensorValue = analogRead(sensorPin);
    if (sensorValue<400)
    {
      digitalWrite(grnPin, HIGH);
      digitalWrite(redPin, LOW);
      // fade out blue
      byte on = i;
      byte off = 255-on;
      for( byte a=0; a<255; a++ ) {
        digitalWrite(bluPin, HIGH);
        delayMicroseconds(on);
        digitalWrite(bluPin, LOW);
        delayMicroseconds(off);
      }
    }
    else if (sensorValue>650){ // set the LED OFF // lower number for on when darker or raise number for on when brighter
      ledsOff();
    }
  }
}
    
    
void redtoyellow() //red to yellow
{

  for(byte i=1; i<255; i++) {
    sensorValue = analogRead(sensorPin);
    if (sensorValue<400)
    {
      digitalWrite(bluPin, HIGH);
      digitalWrite(redPin, LOW);
      // fade in green
      byte on = 255-i;
      byte off = i;
      for( byte a=0; a<255; a++ ) {
        digitalWrite(grnPin, HIGH);
        delayMicroseconds(on);
        digitalWrite(grnPin, LOW);
        delayMicroseconds(off);
      }
    }
    else if (sensorValue>650){ // set the LED OFF // lower number for on when darker or raise number for on when brighter
      ledsOff();
    }
  }
}
    
    
void yellowtogreen()  //yellow to green
{

  for(byte i=1; i<255; i++) {
    sensorValue = analogRead(sensorPin);
    if (sensorValue<400)
    {
      digitalWrite(bluPin, HIGH);
      digitalWrite(grnPin, LOW);
      // fade out red
      byte on = i;
      byte off = 255-on;
      for( byte a=0; a<255; a++ ) {
        digitalWrite(redPin, HIGH);
        delayMicroseconds(on);
        digitalWrite(redPin, LOW);
        delayMicroseconds(off);
      }
    }
    else if (sensorValue>650){ // set the LED OFF // lower number for on when darker or raise number for on when brighter
      ledsOff();
    }
  }
}
    
    
void greentocyan()  //  green to cyan
{

  for(byte i=1; i<255; i++) {
    sensorValue = analogRead(sensorPin);
    if (sensorValue<400)
    {
      digitalWrite(redPin, HIGH);
      digitalWrite(grnPin, LOW);
      // fade in blue
      byte on = 255-i;
      byte off = i;
      for( byte a=0; a<255; a++ ) {
        digitalWrite(bluPin, HIGH);
        delayMicroseconds(on);
        digitalWrite(bluPin, LOW);
        delayMicroseconds(off);
      }
    }
    else if  (sensorValue>650){ // set the LED OFF // lower number for on when darker or raise number for on when brighter
      ledsOff();
    }
  }
}
    
    
void ledsOff()  {
  digitalWrite(redPin, HIGH);  //  turn red pin off
  digitalWrite(grnPin, HIGH);  //  turn green pin off
  digitalWrite(bluPin, HIGH);  //  turn blue pin off
}




