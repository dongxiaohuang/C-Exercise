#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee{
private:
    /* data */
    int _level;
    void enjoying() override;
public:
    Manager (int level, const char* name, Office& office);
    friend ostream& operator<< (ostream& o, const Manager& m);
    ~Manager ();
    void scoldEmploy();
    void paycut(float) override; // to indicate its base class function is virtual
    void payrise(float);
};

#endif
