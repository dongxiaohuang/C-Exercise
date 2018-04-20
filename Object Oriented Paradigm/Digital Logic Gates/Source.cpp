#include "Source.h"
Source::Source(const char* name, bool state) : Gate(name),_state(state){}
bool Source::state(){
    return _state;
}
void Source::print(){
    Gate::print(); // or
    // (Gate) *this.print() //illegal
    cout << (_state? " (1)": " (0)");
}
Source::~Source(){}
