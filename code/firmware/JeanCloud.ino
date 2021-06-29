#include "LightController.h"
#include <FastLED.h>
#include <WiFi.h>

// fastLED configuration:
#define NUM_LEDS 27        // set number of LEDs here
#define LED_PIN 14
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS]; // Define the array of ledsw

LightController lightController = LightController();

void setup() {
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    fill_solid( leds, NUM_LEDS, CRGB(lightController.getRed(), lightController.getGreen(), lightController.getBlue()));
    FastLED.setBrightness(sliderValue.toInt());
    FastLED.show();
}

void loop() {
  // put your main code here, to run repeatedly:

}
