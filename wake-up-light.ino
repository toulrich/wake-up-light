#include "WakeUpLight.h"
#include <FastLED.h>

#define LED_PIN     2
#define COLOR_ORDER GRB
#define CHIPSET     WS2811
#define NUM_LEDS    10

#define BRIGHTNESS  30 // [0,255]
#define FRAMES_PER_SECOND 30

#define POT_PIN     0    // select the input pin for the potentiometer

bool gReverseDirection = false;
int pot_val = 0;       // variable to store the value coming from the potentiometer
int brightness_val = 0; // mapped to brightness range

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(74880);

  delay(3000); // sanity delay
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness( BRIGHTNESS );

}

void loop() {
  pot_val = analogRead(POT_PIN);
  brightness_val = map(pot_val, 0, 1023, 50, 255);
  Serial.println(brightness_val);
  FastLED.setBrightness(brightness_val);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].r = 255;
    leds[i].g = 147;
    leds[i].b = 41;
    // 255, 172, 68 is warm white
    // 255, 147, 41 is candle light
  }
  FastLED.show(); // display this frame
  delay(30);

}
