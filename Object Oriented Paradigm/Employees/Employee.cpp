#include "Employee.h"

Employee::Employee(float salary, const char* name, Office& office):_name(name),_office(&office), _salary(salary){
    // cout << "Employee::Employee()" << endl;
}

ostream& operator<< (ostream& o, const Employee& e){
    return o << e._name << " earns " << e._salary ;
}

Employee::~Employee(){
    // cout << "Employee::~Employee()" << endl;
}

void Employee::paycut(float num){
    _salary -= num;
}
void Employee::payrise(float num){
    _salary += num;
}
void Employee::enjoying(){
    cout << "at home watching TV!" << endl;
}
void Employee::holiday(){
    //behaviors that have shared parts and unique parts
    cout << "enjoy holiday "; // shared parts
    enjoying(); // local function calls ; unique call because
    // this -> enjoying() is a dynamic call
}
void Employee::sayhi(){
    cout << "hi" <<endl;
}
