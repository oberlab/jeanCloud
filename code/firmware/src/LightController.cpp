#include "Arduino.h"
#include "LightController.h"
#include <FastLED.h>

LightController::LightController(int _NUM_LEDS) {
  red = 255;
  blue = 255;
  green = 255;
  intensity = 255;
  NUM_LEDS = _NUM_LEDS;
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

void LightController::setPattern() {

}

int LightController::getRed() { return red; }

int LightController::getGreen() { return green; }

int LightController::getBlue() { return blue; }
