#include "AlarmDoor.h"
AlarmDoor::AlarmDoor(int code): _code(code){}
void AlarmDoor::enterCode(int code){
    if(code == _code){
        if(isActive()){
            cout << "Door is now deactive"<<endl;
            reset();
        }else{
            cout << "Door is now active"<<endl;
            set();
        }
    }else{
        cout << " wrong pin" << endl;
    }
}
void AlarmDoor::open(){
    if(isActive())
        callPolice();
    else{
        cout << "Door is open" << endl;
    }
}
AlarmDoor::~AlarmDoor (){}
