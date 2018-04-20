#ifndef ALARM_DOOR_H
#define ALARM_DOOR_H
#include "Alarm.h"

class AlarmDoor : private Alarm{
    // because Alarmdoor is nit an Alarm
    //only use certain features of Alarm

private:
    /* data */
    int _code;
public:
    using Alarm::isActive;
    AlarmDoor (int code);
    void open();
    void enterCode(int code);
    virtual ~AlarmDoor ();
};
#endif
