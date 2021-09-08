#include "LightController.h"
#include <FastLED.h>
#include <TM1637Display.h>

// Define the connections pins for display:
#define CLK 18
#define DIO 5

uint8_t text[] = {
  SEG_G,                                            // _
  SEG_G,                                            // _
  SEG_G,                                            // _
  SEG_G,                                            // _
  SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G,    // A
  SEG_E | SEG_G,                                    // r
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,            // d
  SEG_C | SEG_D | SEG_E,                            // u
  SEG_C,                                            // i
  SEG_C | SEG_E | SEG_G,                            // n
  SEG_C | SEG_D | SEG_E | SEG_G,                    // o
  SEG_G,                                            // _
  SEG_G,                                            // _
  SEG_G,                                            // _
  SEG_G,                                            // _
  };

// Create display object:
TM1637Display display = TM1637Display(CLK, DIO);

LightController lightController = LightController();

void setup() {
    Serial.begin(115200);

     // setup display
    display.setBrightness(7); // Set the display brightness (0-7)
    display.clear(); // Clear the display

    lightController.on();
    delay(1000);


}

void loop() {
  lightController.runner();
}
