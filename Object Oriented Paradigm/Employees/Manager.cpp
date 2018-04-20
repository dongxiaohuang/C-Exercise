#include "Manager.h"

Manager::Manager(int level, const char* name, Office& office):Employee(10000.0*level, name, office), _level(level){
    // cout << "Manager::Manager()" << endl;
}
ostream& operator<< (ostream& o,  const Manager& m){ // if dont use reference it will copy and then desctruct without construct
    return o << (Employee) m << " at level " << m._level; // it will copy a Employee Object and desctruct
}

Manager::~Manager(){
    // cout << "Manager::~Manager()" << endl;
}


void Manager::paycut(float num){
    _salary -= num*_level;
}
void Manager::payrise(float num){
    _salary += num*_level;
}
void Manager::scoldEmploy(){cout << "Manager's right" << endl;}
void Manager::enjoying(){
    cout <<"at beach enjoying sunshine!" << endl;
}
