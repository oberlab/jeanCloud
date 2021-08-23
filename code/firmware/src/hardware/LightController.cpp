#include "Arduino.h"
#include "LightController.h"
#include <FastLED.h>

// fastLED configuration:
#define NUM_LEDS 27        // set number of LEDs here
#define LED_PIN 14
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS]; // Define the array of ledsw

LightController::LightController() {
  red = 255;
  blue = 255;
  green = 255;
  intensity = 255;
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  fill_solid( leds, NUM_LEDS, CRGB(255, 255, 255));
}

void LightController::on() {
  FastLED.setBrightness(intensity);
  FastLED.show();
}

void LightController::off() {
  FastLED.setBrightness(0);
  FastLED.show();
}

void LightController::setRGB(int _red, int _green, int _blue) {
  red = _red;
  green = _green;
  blue = _blue;
  fill_solid( leds, NUM_LEDS, CRGB(red, green, blue));
}

void LightController::setIntenstiy(int _intensity) {
  intensity = _intensity;
}

void LightController::fadeBlue() {
  static uint8_t color;
  EVERY_N_MILLISECONDS(180) {
    fadeToBlackBy( leds, NUM_LEDS, 230);
    static uint8_t i = 0;
    leds[i] = CHSV( color+random8(0,10), 160, 255 );
    i++;
    if (i == NUM_LEDS) { i = 0; }  //reset

    //copy ledsA data to leds
    for (uint8_t i=0; i<NUM_LEDS; i++) { leds[i] = leds[i]; }
  }

  EVERY_N_SECONDS(2) {
    color = random8();
  }
}

void LightController::setPattern() {}

int LightController::getIntenstiy() { return intensity; }

int LightController::getRed() { return red; }

int LightController::getGreen() { return green; }

int LightController::getBlue() { return blue; }

bool LightController::isActive() { return FastLED.getBrightness() > 0; }
