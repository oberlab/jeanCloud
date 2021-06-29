#include "Arduino.h"
#include "Webserver.h"
#include "LightController.h"
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "SPIFFS.h"


String processor(const String& var) {
  return String();
}

Webserver::Webserver(LightController _lightController) : server(80) {
    lightController = _lightController;
}

void Webserver::setup() {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", "text/html");
  });

  server.serveStatic("/", SPIFFS, "/");

  server.on("/lamp/on", HTTP_GET, [&] (AsyncWebServerRequest *request) {

    Serial.println("Lamp on my G");

    lightController.on();
    request->send(200, "text/plain", "OK");
  });
}

void Webserver::begin() { server.begin(); }
