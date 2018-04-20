#include "And.h"

And::And(const char* name, Gate* pin1, Gate* pin2):BinaryGate(name, pin1, pin2){}

bool And::calculate(Gate *pin1, Gate *pin2){
    return pin1->state()* pin2->state();
}
And::~And(){}
