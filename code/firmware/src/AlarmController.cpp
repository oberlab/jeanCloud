#include "Arduino.h"
#include "AlarmController.h"

// Define the pin for the buzzer and configurate it:
#define BUZ 32
int freq = 2000;
int channel = 0;
int resolution = 8;

AlarmController::AlarmController() {
    alarmHour = 21;
    alarmMinute = 57;
    alarmStatus = true;

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

void AlarmController::makeNoise(bool triggered) {
    if (triggered){
      ledcWrite(channel, 150);
      ledcWriteTone(channel, 4000);
      delay(100);
      ledcWriteTone(channel, 0);
      delay(500);
      ledcWriteTone(channel, 4000);
      delay(100);
      ledcWriteTone(channel, 0);
    }

}

bool AlarmController::checkAlarm(int hour, int minute, bool status) {
    if (hour == alarmHour && minute == alarmMinute && status) {
        return true;
    } else {
        return false;
    }
}

bool AlarmController::getAlarmStatus(){
    return alarmStatus;
}

int AlarmController::getHour() { return alarmHour; }

int AlarmController::getMinute() { return alarmMinute; }
