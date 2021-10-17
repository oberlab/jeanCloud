#include "Arduino.h"
#include "LightController.h"
#include <FastLED.h>

// fastLED configuration:
#define NUM_LEDS 27        // set number of LEDs here
#define LED_PIN 14
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS]; // Define the array of ledsw

int x = 0;
bool up = true;

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



void LightController::bounce() {
  EVERY_N_MILLIS(50){
    Serial.println(x);
    fill_solid( leds, NUM_LEDS, CRGB(0, 0, 0));
    leds[x] = CRGB(255, 255, 255);
    leds[x+1] = CRGB(255, 255, 255);
    leds[x+2] = CRGB(255, 255, 255);
    FastLED.show();

    if (x < NUM_LEDS-3 && up) {
      x++;
    } else if (x == NUM_LEDS-3 && up) {
      up = false;
      x--;
    } else if (x == 0 && !up) {
      up = true;
    } else {
      x--;
    }
  }
}

void LightController::runner() {
  EVERY_N_MILLIS(100){
    Serial.print(x);
    fill_solid( leds, NUM_LEDS, CRGB(0, 0, 0));
    leds[x] = CRGB(255, 255, 255);
    if (x > 0) {
      leds[x-1] = CRGB(255, 255, 255);
      Serial.print(x)-1;
    } else {
      leds[NUM_LEDS-2] = CRGB(255, 255, 255);
    }

    if (x > 1) {
      leds[x-2] = CRGB(255, 255, 255);
      Serial.println(x-2);
    } else {
      leds[NUM_LEDS-1] = CRGB(255, 255, 255);
      Serial.print(NUM_LEDS-1);
    }

    FastLED.show();

    if (x < NUM_LEDS ) {
      x++;
    } else {
      x = 0;
    }
  }
}

void LightController::setPattern() {}

int LightController::getIntenstiy() { return intensity; }

int LightController::getRed() { return red; }

int LightController::getGreen() { return green; }

int LightController::getBlue() { return blue; }

bool LightController::isActive() { return FastLED.getBrightness() > 0; }
