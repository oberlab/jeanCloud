#ifndef LightController_h
#define LightController_h

class LightController
{
    public:
        void on();
        void off();
        void setRGB(int _red, int _green, int _blue);
        void setIntenstiy(int _intenstiy);
        void setPattern();

    private:
        int red;
        int green;
        int blue;
        int intenstiy;
};


#endif