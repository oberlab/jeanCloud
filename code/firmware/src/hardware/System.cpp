#include <Arduino.h>
#include <SPIFFS.h>
#include <WiFi.h>
#include "System.h"
#include "../PasswordController.h"

bool System::connectToWifi(PasswordController *passwordController)
{
  int connectionTries = 0;
  WiFi.begin(passwordController->getSSID().c_str(), passwordController->getPassword().c_str());
  while (WiFi.status() != WL_CONNECTED && connectionTries <= 20)
  {
    delay(1000);
    Serial.println(passwordController->getSSID().c_str());
    Serial.println(passwordController->getPassword().c_str());
    Serial.print("Connecting to WiFi.. Try: ");
    Serial.println(connectionTries);
    connectionTries++;
  }

  return WiFi.status() == WL_CONNECTED;
}

void System::initFS()
{
  if (!SPIFFS.begin())
  {
    Serial.println("An error has occurred while mounting SPIFFS");
  }
  else
  {
    Serial.println("SPIFFS mounted successfully");
  }
}