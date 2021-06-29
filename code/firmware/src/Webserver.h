#ifndef Webserver_h
#define Webserver_h

#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

class Webserver
{
    public:
        void setup();
        void begin();

    private:
        AsyncWebServer server;
};


#endif