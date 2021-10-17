#ifndef System_h
#define System_h
#include "../PasswordController.h"

class System
{
public:
    static bool connectToWifi(PasswordController *passwordController);
    static void initFS();
};

#endif
