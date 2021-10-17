#include <Arduino.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include <TM1637Display.h>
#include "Webserver.h"
#include "./hardware/LightController.h"
#include "PasswordController.h"

Webserver::Webserver(int port, LightController _lightController, AlarmController *_alarmController, TM1637Display *_display) : server(port)
{
  lightController = _lightController;
  alarmController = _alarmController;
  display = _display;
  processor = [&](const String &var)
  {
    if (var == "LIGHT")
    {
      if (lightController.isActive())
      {
        return String("checked");
      }
      return String();
    }
    else if (var == "INTENSITY")
    {
      return String(lightController.getIntenstiy());
    }
    else if (var == "RED")
    {
      return String(lightController.getRed());
    }
    else if (var == "GREEN")
    {
      return String(lightController.getGreen());
    }
    else if (var == "BLUE")
    {
      return String(lightController.getBlue());
    }
    else if (var == "ALARM")
    {
      if (alarmController->getAlarmStatus())
      {
        return String("checked");
      }
      return String();
    }
    else if (var == "HOUR")
    {
      return String(alarmController->getHour());
    }
    else if (var == "MINUTE")
    {
      return String(alarmController->getMinute());
    }

    return String();
  };
}

void Webserver::setupAP()
{
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/indexAP.html", "text/html"); });

  server.serveStatic("/", SPIFFS, "/");

  server.on("/wifi", HTTP_GET, [&](AsyncWebServerRequest *request)
            {
              const char *PARAM_INPUT_SSID = "ssid";
              const char *PARAM_INPUT_PASSWORD = "password";

              String ssid = "";
              String password = "";

              String inputMessage = "No message sent";

              if (request->hasParam(PARAM_INPUT_SSID))
              {
                inputMessage = request->getParam(PARAM_INPUT_SSID)->value();
                ssid = inputMessage;
              }

              if (request->hasParam(PARAM_INPUT_PASSWORD))
              {
                inputMessage = request->getParam(PARAM_INPUT_PASSWORD)->value();
                password = inputMessage;
              }

              PasswordController passwordController = PasswordController("/wifi.txt");
              passwordController.writeCredentials(ssid, password);

              request->send(200, "text/plain", "OK");
              delay(1000);
              ESP.restart();
            });
  Serial.println("AP Webserver setup complete");
}

void Webserver::setup()
{
  server.on("/", HTTP_GET, [&](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/index.html", "text/html", false, processor); });

  server.serveStatic("/", SPIFFS, "/");

  server.on("/lamp/on", HTTP_GET, [&](AsyncWebServerRequest *request)
            {
              Serial.println("Lamp on my G");

              lightController.on();
              request->send(200, "text/plain", "OK");
            });

  server.on("/lamp/off", HTTP_GET, [&](AsyncWebServerRequest *request)
            {
              Serial.println("Lamp off my G");

              lightController.off();
              request->send(200, "text/plain", "OK");
            });

  server.on("/lamp/intenstiy", HTTP_GET, [&](AsyncWebServerRequest *request)
            {
              const char *PARAM_INPUT = "value";
              String inputMessage;
              if (request->hasParam(PARAM_INPUT))
              {
                inputMessage = request->getParam(PARAM_INPUT)->value();
                lightController.setIntenstiy(std::atoi(inputMessage.c_str()));
                lightController.on();
              }
              else
              {
                inputMessage = "No message sent";
              }
              Serial.println(inputMessage);
              request->send(200, "text/plain", "OK");
            });

  server.on("/display/intenstiy", HTTP_GET, [&](AsyncWebServerRequest *request)
            {
              const char *PARAM_INPUT = "value";
              String inputMessage;
              if (request->hasParam(PARAM_INPUT))
              {
                inputMessage = request->getParam(PARAM_INPUT)->value();
                display->setBrightness(std::atoi(inputMessage.c_str()));
              }
              else
              {
                inputMessage = "No message sent";
              }
              Serial.println(inputMessage);
              request->send(200, "text/plain", "OK");
            });

  server.on("/lamp/color", HTTP_GET, [&](AsyncWebServerRequest *request)
            {
              const char *PARAM_INPUT_RED = "red";
              const char *PARAM_INPUT_GREEN = "green";
              const char *PARAM_INPUT_BLUE = "blue";

              int red = lightController.getRed();
              int green = lightController.getGreen();
              int blue = lightController.getBlue();

              String inputMessage = "No message sent";
              ;
              if (request->hasParam(PARAM_INPUT_RED))
              {
                inputMessage = request->getParam(PARAM_INPUT_RED)->value();
                red = std::atoi(inputMessage.c_str());
              }

              if (request->hasParam(PARAM_INPUT_GREEN))
              {
                inputMessage = request->getParam(PARAM_INPUT_GREEN)->value();
                green = std::atoi(inputMessage.c_str());
              }

              if (request->hasParam(PARAM_INPUT_BLUE))
              {
                inputMessage = request->getParam(PARAM_INPUT_BLUE)->value();
                blue = std::atoi(inputMessage.c_str());
              }

              lightController.setRGB(red, green, blue);
              lightController.on();

              Serial.println(inputMessage);
              request->send(200, "text/plain", "OK");
            });

  server.on("/alarm/on", HTTP_GET, [&](AsyncWebServerRequest *request)
            {
              Serial.println("Alarm on, Bro");

              alarmController->on();
              request->send(200, "text/plain", "OK");
            });

  server.on("/alarm/off", HTTP_GET, [&](AsyncWebServerRequest *request)
            {
              Serial.println("Alarm off, Bro");

              alarmController->off();
              request->send(200, "text/plain", "OK");
            });

  server.on("/alarm/set", HTTP_GET, [&](AsyncWebServerRequest *request)
            {
              const char *PARAM_INPUT_HOUR = "hour";
              const char *PARAM_INPUT_MINUTE = "minute";

              int hour = 0;
              int minute = 0;

              String inputMessage = "No message sent";

              if (request->hasParam(PARAM_INPUT_HOUR))
              {
                inputMessage = request->getParam(PARAM_INPUT_HOUR)->value();
                hour = std::atoi(inputMessage.c_str());
              }

              if (request->hasParam(PARAM_INPUT_MINUTE))
              {
                inputMessage = request->getParam(PARAM_INPUT_MINUTE)->value();
                minute = std::atoi(inputMessage.c_str());
              }

              alarmController->setAlarm(hour, minute);

              Serial.println(inputMessage);
              request->send(200, "text/plain", "OK");
            });
}

void Webserver::begin() { server.begin(); }
void Webserver::end() { server.end(); }
