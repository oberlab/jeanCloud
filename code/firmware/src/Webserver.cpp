#include "Arduino.h"
#include "Webserver.h"
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "SPIFFS.h"


String processor(const String& var) {
  return String();
}

Webserver::Webserver():server(80) {
}

void Webserver::setup() {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", "text/html");
  });
}

void Webserver::begin() { server.begin(); }
