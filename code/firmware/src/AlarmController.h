#ifndef alarmController_h
#define alarmController_h

class AlarmController
{
    public:
        AlarmController();
        void on();
        void off();
        void setAlarm(int hour, int minute);
        void makeNoise(bool triggered);
        bool checkAlarm(int hour, int minute, bool status);
        bool getAlarmStatus();
        int getHour();
        int getMinute();

    private:
        int alarmHour;
        int alarmMinute;
        bool alarmStatus;
};
#endif
