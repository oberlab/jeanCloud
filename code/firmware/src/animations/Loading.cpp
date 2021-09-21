#include "Arduino.h"
#include "LEDAnimation.h"
#include "../hardware/LightController.h"

#ifndef Loading_cpp
#define Loading_cpp

class Loading : public LEDAnimation {
    public:
        void animate() {
            Serial.print("Loading");
            LightController lightController = LightController();
            lightController.runner();
        }
};

#endif