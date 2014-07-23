#include <Adafruit_NeoPixel.h>
#define PIN 0
Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

//Rainbow function: input is wait time between changes
void rainbow(uint8_t wait) {
  uint16_t i, j;
  for (j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}
//setColor function: input is (strip.Color(xxx,xxx,xxx),brightness)
// strip.color values are RGB
// brightness value is 0-255
void setColor( uint32_t c, uint8_t bright) {
  uint16_t i;
  for(i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.setBrightness(bright);
    strip.show();
  }
}
//throb function: input is strip.Color values, delay
void throb (uint32_t c, uint8_t wait) {
  for (int i=0; i<255; i++) {
setColor(c,i);
delay(wait);
}
for (int i=255; i>0; i--) {
  setColor(c,i);
  delay(wait);
}
}
void loop(){
  for (int i=0;i<10;i++)
  {
throb(strip.Color(255,0,0),4);
  }
}

