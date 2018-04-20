#ifndef BINARY_GATE_H
#define BINARY_GATE_H
#include "Gate.h"
class BinaryGate : public Gate {
private:
    /* data */
    Gate* _pin1;
    Gate* _pin2;
public:
    BinaryGate (const char* name, Gate* pin1, Gate* pin2);
    bool state() override;
    void print() override;
    virtual bool calculate(Gate* pin1, Gate* pin2) = 0;
    virtual ~BinaryGate ();
};
#endif
