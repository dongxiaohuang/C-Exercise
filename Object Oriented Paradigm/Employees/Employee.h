#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include "Office.h"
#include "Desk.h"
using namespace std;
class Employee {
    const char* _name;
    Office* _office; // shared
    Desk my_desk; //private
    virtual void enjoying();
protected:
    float _salary; // otherwise it can not be accessed by derivatives
public:
    Employee(float salary, const char* name, Office& office);
    friend ostream& operator<< (ostream& o, const Employee& e);
    virtual ~Employee();
    virtual void paycut(float);
    void payrise(float);
    void holiday();
    void sayhi();
};
#endif
