#include <Arduino.h>
#include <ESPmDNS.h>
#include "MDNSController.h"

MDNSController::MDNSController(char *_hostname, char *_instanceName)
{
    hostname = _hostname;
    instanceName = _instanceName;
}

bool MDNSController::setup()
{
    if (!MDNS.begin(hostname))
    {
        Serial.println("Error setting up MDNS responder!");
        return false;
    }
    Serial.println("mDNS responder started");

    MDNS.setInstanceName(instanceName);
    MDNS.addService("http", "tcp", 80);
    return true;
}