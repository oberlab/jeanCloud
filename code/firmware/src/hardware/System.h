#ifndef System_h
#define System_h
#include "../PasswordController.h"
#include "../animations/Loading.cpp"

class System
{
    public:
        static bool connectToWifi(PasswordController *passwordController, Loading animation);
        static void initFS();
};


#endif
