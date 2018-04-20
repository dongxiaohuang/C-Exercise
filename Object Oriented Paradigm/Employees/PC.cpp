#include "PC.h"

PC::PC(){
        // cout << "PC::PC()" << endl;
}
PC::~PC(){
        // cout << "PC::~PC()" << endl;
}
void PC::turnOn(){
    state = ON;
    // cout << "PC is ON" << endl;
}
void PC::turnOff(){
    state = OFF;
    // cout << "PC is OFF" << endl;
}
