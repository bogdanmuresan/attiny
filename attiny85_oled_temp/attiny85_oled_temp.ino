#include <Arduino.h>
#include <U8x8lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif

#include <DHT.h>

#define DHTPIN 0    
#define DHTTYPE DHT11

U8X8_SSD1306_128X32_UNIVISION_SW_I2C u8x8(/* clock=*/ 1, /* data=*/ 2, /* reset=*/ U8X8_PIN_NONE);   // Adafruit Feather ESP8266/32u4 Boards + FeatherWing OLED
DHT dht(DHTPIN, DHTTYPE);

char tempMsg[25];
char humMsg[25];

void setup(void)
{
 
  dht.begin();  
  u8x8.begin();
  u8x8.setPowerSave(0);
}

void loop(void)
{
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  u8x8.setFont(u8x8_font_chroma48medium8_r);
  dtostrf(t, 7, 3, tempMsg);


  //sprintf(tempMsg, "Temp: %.2f *C", t);
  u8x8.drawString(0,1,tempMsg);
  delay(200);
  u8x8.clearDisplay();
  //sprintf(humMsg, "Hum: %.2f ", h);
  //u8x8.drawString(0,1,humMsg);  
}
