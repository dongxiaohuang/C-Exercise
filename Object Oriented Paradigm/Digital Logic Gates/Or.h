#ifndef OR_H
#define OR_H

#include "BinaryGate.h"
class Or : public BinaryGate{
private:
    /* data */
protected:
    bool calculate(Gate* pin1, Gate* pin2) override;
public:
    Or(const char* name, Gate* pin1, Gate* pin2);
    virtual ~Or ();
};
#endif
