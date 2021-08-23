#include "Arduino.h"
#include "LEDAnimation.h"
#include "../hardware/LightController.h"

class Loading : public LEDAnimation {
    void animate() {
        Serial.print("Loading");
        LightController lightController = LightController();
        lightController.fadeBlue();
    }
};
