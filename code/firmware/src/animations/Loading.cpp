#include "Arduino.h"
#include "LEDAnimation.h"
#include "../hardware/LightController.h"

class Loading : public LEDAnimation {
    void animation() {
        Serial.print("Loading");
        LightController lightController = LightController();
        lightController.fadeBlue()
    }
};
