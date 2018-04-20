#include "Alarm.h"

Alarm::Alarm(){set();}
Alarm::~Alarm(){}
void Alarm::set(){ _state = true;}
void Alarm::reset(){ _state = false;}
bool Alarm::isActive() const { return _state == true;}
void Alarm::callPolice(){ cout << "Police on the way" << endl;}
