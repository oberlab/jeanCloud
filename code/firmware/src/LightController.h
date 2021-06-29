#ifndef LightController_h
#define LightController_h

class LightController
{
    public:
        LightController();
        void on();
        void off();
        void setRGB(int _red, int _green, int _blue);
        void setIntenstiy(int _intensity);
        void setPattern();
        int getRed();
        int getGreen();
        int getBlue();

    private:
        int red;
        int green;
        int blue;
        int intensity;
};


#endif
