#ifndef ALARM_H
#define ALARM_H
#include <iostream>
using namespace std;

class Alarm {
private:
    /* data */
    bool _state;
public:
    Alarm ();
    void set();
    void reset();
    bool isActive() const;
    void callPolice();
    virtual ~Alarm ();
};
#endif
