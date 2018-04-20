#include "Gate.h"
Gate::Gate(const char* name) : _name(name){}
void Gate:: print(){
    std::cout << _name ;
}
Gate::~Gate(){
    
}
