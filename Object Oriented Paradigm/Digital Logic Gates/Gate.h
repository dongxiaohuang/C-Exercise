#ifndef GATE_H
#define GATE_H
#include <iostream>
using namespace std;

class Gate {
private:
    /* data */
    const char* _name;
public:
    Gate (const char* name);
    virtual bool state() = 0;//pure function
    virtual void print();
    virtual ~Gate ();
};
#endif
