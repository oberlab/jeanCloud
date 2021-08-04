#ifndef ButtonController_h
#define ButtonController_h
#include <FastLED.h>

class ButtonController
{
    public:
        ButtonController(uint pin);

    private:
        int red;
        int green;
        int blue;
        int intensity;
};

#endif
