#include <Arduino.h>
#include <SPIFFS.h>
#include "PasswordController.h"

String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = {0, -1};
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++)
    {
        if (data.charAt(i) == separator || i == maxIndex)
        {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i + 1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

PasswordController::PasswordController(String _path)
{
    path = _path;
    exists = SPIFFS.exists(_path);
    if (exists)
    {
        File file = SPIFFS.open(_path, "r");
        String result = file.readString();
        ssid = getValue(result, '\n', 0);
        ssid = ssid.substring(0, ssid.length() - 1);
        password = getValue(result, '\n', 1);
    }
    else
    {
        ssid = "";
        password = "";
    }
}

void PasswordController::writeCredentials(String _ssid, String _password)
{
    File file = SPIFFS.open(path, FILE_WRITE);
    if (!file)
    {
        Serial.println("There was an error opening the file for writing");
        return;
    }
    ssid = _ssid;
    password = _password;
    file.println(ssid);
    file.print(password);
    file.close();
}

String PasswordController::getSSID()
{
    return ssid;
}

String PasswordController::getPassword()
{
    return password;
}

bool PasswordController::isExisting()
{
    return exists;
}
