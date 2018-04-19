#ifndef TABLELAMP_H
#define TABLELAMP_H
#include <iostream>

class TableLamp{
    enum {ON, OFF} state;
public:
    TableLamp();
    void pressSwitch();
    friend std::ostream& operator<< (std::ostream& o, const TableLamp& t);
};
#endif
