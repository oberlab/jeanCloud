#include "Arduino.h"
#include "SPIFFS.h"
#include "PasswordController.h"

String getValue(String data, char separator, int index) {
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

PasswordController::PasswordController(String _path) {
    path = _path;
    exists = SPIFFS.exists(_path);
    if (exists) {
        File file = SPIFFS.open(_path, "r");
        String result = file.readString();
        ssid = getValue(result, '\n', 0);
        password = getValue(result, '\n', 1);
    } else {
        ssid = "";
        password = "";
    }
}

PasswordController::writeCredentials(String _ssid, String _password) {
    ssid = _ssid;
    password = _password;
    // Todo: Write File
    File file = SPIFFS.open(_path, FILE_WRITE);
    file.println(ssid);
    file.println(password);
    file.close();
}

PasswordController::getSSID() {
    return ssid;
}

PasswordController::getPassword() {
    return password;
}

PasswordController::isExisting() {
    return exists;
}
