#include <Adafruit_NeoPixel.h>
#define PIN 0
Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  for (int i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i,255,0,0);
    strip.show();
  }
}

