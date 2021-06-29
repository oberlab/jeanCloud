#include "Arduino.h"
#include "Webserver.h"
#include <ESPAsyncWebServer.h>

String processor(const String& var) {  
  return String();
}

Webserver::Webserver() {
    server(80);
}

void Webserver::setup() {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", "<html><head><title>Jean Cloud</title></head></html>", processor);
  });
}

void Webserver::begin() { server.begin(); }