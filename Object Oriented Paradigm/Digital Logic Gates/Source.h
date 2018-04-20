#ifndef SOURCE_H
#define SOURCE_H
#include "Gate.h"
class Source :public Gate{
private:
    /* data */
    bool _state;
public:
    Source (const char* name, bool state);
    bool state() override;
    virtual ~Source ();
    void print() override;
};
#endif
