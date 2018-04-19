#ifndef ADJTABLELAMP_H
#define ADJTABLELAMP_H
#include "TableLamp.h"
class AdjTableLamp: public TableLamp{
    float brightness;
public:
    void dim();
    AdjTableLamp();
    friend std::ostream& operator<< (std::ostream& o, const AdjTableLamp& at);
};

#endif
