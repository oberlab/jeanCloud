#ifndef Webserver_h
#define Webserver_h

#include "LightController.h"
#include "AlarmController.h"
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

class Webserver
{
    public:
        Webserver(LightController _lightController, AlarmController _alarmController);
        void setup();
        void begin();

    private:
        AsyncWebServer server;
        LightController lightController;
        AlarmController alarmController;
};


#endif