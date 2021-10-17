#ifndef Webserver_h
#define Webserver_h

#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <TM1637Display.h>
#include "./hardware/LightController.h"
#include "AlarmController.h"
#include "PasswordController.h"

typedef std::function<String(const String &)> AwsTemplateProcessor;

class Webserver
{
public:
    Webserver(int port, LightController _lightController, AlarmController *_alarmController, TM1637Display *_display);
    void setup();
    void setupAP();
    void begin();
    void end();

private:
    AsyncWebServer server;
    LightController lightController;
    AlarmController *alarmController;
    TM1637Display *display;
    AwsTemplateProcessor processor;
};

#endif
