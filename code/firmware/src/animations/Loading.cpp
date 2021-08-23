#include "Arduino.h"
#include "LEDAnimation.h"

class Loading : public LEDAnimation {
    void animation() {
        Serial.print("Loading");
    }
};