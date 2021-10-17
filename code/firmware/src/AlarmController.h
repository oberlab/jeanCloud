#ifndef alarmController_h
#define alarmController_h

#include "./hardware/LightController.h"

class AlarmController
{
public:
    AlarmController(LightController *_lightController);
    void on();
    void off();
    void setAlarm(int hour, int minute);
    void stopAlarm();
    void snooze();
    void makeNoise();
    void loop(int hour, int minute);
    bool getAlarmStatus();
    int getHour();
    int getMinute();

private:
    LightController *lightController;
    int alarmHour;
    int alarmMinute;
    int snoozeMinute;
    int snoozeCount;
    bool alarmStatus;
    bool alarmStopped;
    bool beeping;
    bool compareAlarmMinutes(int hour, int minute, int offset);
};
#endif
