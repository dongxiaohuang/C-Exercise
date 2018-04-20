#ifndef PC_H
#define PC_H
#include <iostream>
using namespace std;
class PC {
private:
    /* data */
    enum {ON, OFF} state;
public:
    PC ();
    virtual ~PC ();
    void turnOn();
    void turnOff();
};
#endif
