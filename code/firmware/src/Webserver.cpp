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

  server.on("/lamp/off", HTTP_GET, [&] (AsyncWebServerRequest *request) {

    Serial.println("Lamp off my G");

    lightController.off();
    request->send(200, "text/plain", "OK");
  });

  server.on("/lamp/intenstiy", HTTP_GET, [&] (AsyncWebServerRequest *request) {
    const char* PARAM_INPUT = "value";
    String inputMessage;
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value();
      lightController.setIntenstiy(std::atoi(inputMessage.c_str()));
      lightController.on();
    } else {
      inputMessage = "No message sent";
    }
    Serial.println(inputMessage);
    request->send(200, "text/plain", "OK");
  });

  server.on("/lamp/color", HTTP_GET, [&] (AsyncWebServerRequest *request) {
    const char* PARAM_INPUT_RED = "red";
    const char* PARAM_INPUT_GREEN = "green";
    const char* PARAM_INPUT_BLUE = "blue";
    String inputMessage;
    if (request->hasParam(PARAM_INPUT_RED)) {
      inputMessage = request->getParam(PARAM_INPUT_RED)->value();
      lightController.setRGB(std::atoi(inputMessage.c_str()), lightController.getGreen(), lightController.getBlue());
    } 
    else if (request->hasParam(PARAM_INPUT_GREEN)) {
      inputMessage = request->getParam(PARAM_INPUT_GREEN)->value();
      lightController.setRGB(lightController.getRed(), std::atoi(inputMessage.c_str()), lightController.getBlue());
    } 
    else if (request->hasParam(PARAM_INPUT_BLUE)) {
      inputMessage = request->getParam(PARAM_INPUT_BLUE)->value();
      lightController.setRGB(lightController.getRed(), lightController.getGreen(), std::atoi(inputMessage.c_str()));
    } 
    else {
      inputMessage = "No message sent";
    }
    Serial.println(inputMessage);
    request->send(200, "text/plain", "OK");
  });
}

void Webserver::begin() { server.begin(); }
