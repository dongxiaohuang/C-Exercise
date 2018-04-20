#include "Boss.h"

Boss::Boss(const char* name, Office& office):Employee(1.0, name, office){
    // cout << "Boss::Boss()" << endl;
    _pc.turnOn();
}

Boss::~Boss(){
    // cout << "Boss::~Boss()" << endl;
    _pc.turnOff();
}
