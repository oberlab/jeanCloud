#ifndef Webserver_h
#define Webserver_h

#include "LightController.h"
#include "AlarmController.h"
#include "PasswordController.h"
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

class Webserver
{
    public:
        Webserver(int port, LightController _lightController, AlarmController *_alarmController);
        void setup();
        void setupAP(PasswordController *_passwordController);
        void begin();
        void end();

    private:
        AsyncWebServer server;
        LightController lightController;
        AlarmController *alarmController;
};


#endif
