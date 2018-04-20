#ifndef And_H
#define And_H
#include "BinaryGate.h"
class And : public BinaryGate{
private:
    /* data */
protected:
    bool calculate(Gate* pin1, Gate* pin2) override;
public:
    And(const char* name, Gate* pin1, Gate* pin2);
    virtual ~And ();
};
#endif
