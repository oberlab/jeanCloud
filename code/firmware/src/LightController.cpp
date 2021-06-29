#include "Arduino.h"
#include "LightController.h"
#include <FastLED.h>

LightController::LightController() {
  red = 255;
  blue = 255;
  green = 255;
  intensity = 255;
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
}

void LightController::setIntenstiy(int _intensity) {
  intensity = _intensity;
}

void LightController::setPattern() {

}

int LightController::getRed() { return red; }

int LightController::getGreen() { return green; }

int LightController::getBlue() { return blue; }
