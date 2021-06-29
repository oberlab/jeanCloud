#ifndef Webserver_h
#define Webserver_h

#include "LightController.h"
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

class Webserver
{
    public:
        Webserver(LightController _lightController);
        void setup();
        void begin();

    private:
        AsyncWebServer server;
        LightController lightController;
};


#endif