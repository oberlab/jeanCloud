#include "Arduino.h"
#include "AlarmController.h"

// Define the pin for the buzzer and configurate it:
#define BUZ 32
int freq = 2000;
int channel = 0;
int resolution = 8;

AlarmController::AlarmController(LightController *_lightController) {
    lightController = _lightController;
    alarmHour = 8;
    alarmMinute = 0;
    alarmStatus = true;
    snoozeMinute = 5;

    // setup buzzer
    ledcSetup(channel, freq, resolution);
    ledcAttachPin(BUZ, channel);
}

void AlarmController::on() {
    alarmStatus = true;
}

void AlarmController::off() {
    alarmStatus = false;
}

void AlarmController::setAlarm(int hour, int minute) {
    alarmHour = hour;
    alarmMinute = minute;
}

void AlarmController::makeNoise() {
    ledcWrite(channel, 150);
    ledcWriteTone(channel, 4000);
    delay(100);
    ledcWriteTone(channel, 0);
    delay(500);
    ledcWriteTone(channel, 4000);
    delay(100);
    ledcWriteTone(channel, 0);
}

void AlarmController::snooze() {
    if (beeping) {
        beeping = false;
        snoozeCount++;
    }
}

void AlarmController::stopAlarm() {
    if (beeping) {
        beeping = false;
        alarmStopped = true;
    }
}

void AlarmController::loop(int hour, int minute) {
    if (compareAlarmMinutes(hour, minute, 0) && getAlarmStatus()) {
        beeping = true;
        makeNoise();
        lightController->flash_white();
    } else {
        if (compareAlarmMinutes(hour, minute, 1)) {
            snoozeCount = 0;
            alarmStopped = false;
            beeping = false;
        }
    }
}

bool AlarmController::getAlarmStatus() { return alarmStatus && !alarmStopped; }

int AlarmController::getHour() { return alarmHour; }

int AlarmController::getMinute() { return alarmMinute; }

bool AlarmController::compareAlarmMinutes(int hour, int minute, int offset) {
    int alarmMinutes = (alarmHour * 60) + alarmMinute + (snoozeMinute * snoozeCount);
    int currentMinutes = (hour * 60) + minute;
    return (alarmMinutes + offset) == currentMinutes;
}
