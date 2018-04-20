#include "BinaryGate.h"

BinaryGate::BinaryGate(const char* name, Gate* pin1, Gate* pin2):
    Gate(name), _pin1(pin1), _pin2(pin2){}

bool BinaryGate::state(){
    //shared parts
    return calculate(_pin1, _pin2);//unique parts
}
BinaryGate::~BinaryGate(){}
void BinaryGate::print() {
    // (Gate) *this->print(); //illegeal
    Gate::print();//shared part
    //unique part
    cout << "[" ;_pin1->print(); cout << ", "; _pin2->print(); cout<<"]";
    // cout << "[" << _pin1->state() << ", "<< _pin2->state()<<"] "<< endl;

}
