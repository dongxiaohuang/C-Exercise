#include "EmployeeList.h"

EmployeeList::EmployeeList(Employee* employee): _employee(employee), _next(nullptr){}

void EmployeeList::insert(Employee* employee){
    EmployeeList* newList = new EmployeeList(employee);
    newList -> _next = nullptr;
    _next = newList;
}

void EmployeeList::paycut(float a){
    //recursion
    _employee -> paycut(a);
    if(_next != nullptr)
        _next -> paycut(a);
}

ostream& operator<< (ostream& o, const EmployeeList& el){
    o << *el._employee << endl;
    if(el._next != nullptr)
        return o<< *el._next << endl;
    return o;
}

EmployeeList::~EmployeeList (){
    EmployeeList* current= this;
    EmployeeList* next;
    //something wrong
    while(current -> _next != nullptr){
        next = _next;
        delete current -> _employee;
        delete current;
        current = next;
    }
}
