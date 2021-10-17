#ifndef LightController_h
#define LightController_h
#include <FastLED.h>

class LightController
{
public:
    LightController();
    void on();
    void off();
    void setRGB(int _red, int _green, int _blue);
    void setIntenstiy(int _intensity);
    void setPattern();
    void bounce();
    void runner();
    void pulse();
    void flash_white();
    int getIntenstiy();
    int getRed();
    int getGreen();
    int getBlue();
    bool isActive();

private:
    int red;
    int green;
    int blue;
    int intensity;
};

#endif
