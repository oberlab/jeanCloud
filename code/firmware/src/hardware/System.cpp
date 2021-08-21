#include "Arduino.h"
#include "System.h"
#include "../PasswordController.h"
#include <WiFi.h>

bool System::connectToWifi(PasswordController *passwordController) {
    int connectionTries = 0;
    WiFi.begin(passwordController->getSSID().c_str(), passwordController->getPassword().c_str());
    while (WiFi.status() != WL_CONNECTED && connectionTries <= 20) {
      delay(1000);
      Serial.println(passwordController->getSSID().c_str());
      Serial.println(passwordController->getPassword().c_str());
      Serial.print("Connecting to WiFi.. Try: " + connectionTries);
      Serial.println(connectionTries);
      connectionTries++;
    }

    return WiFi.status() == WL_CONNECTED;
}