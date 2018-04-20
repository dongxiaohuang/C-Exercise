#ifndef BOSS_H
#define BOSS_H
#include "Employee.h"
#include "PC.h"
class Boss: public Employee {
private:
    /* data */
    PC _pc;
public:
    Boss (const char* _name, Office& office);
    ~Boss ();
};
#endif
