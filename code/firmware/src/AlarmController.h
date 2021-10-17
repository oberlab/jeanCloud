#ifndef alarmController_h
#define alarmController_h

class AlarmController
{
    public:
        AlarmController();
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
