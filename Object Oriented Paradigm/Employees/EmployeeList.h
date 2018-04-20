#ifndef EMPLOYEELIST_H
#define EMPLOYEELIST_H
#include "Employee.h"
class EmployeeList {
private:
    /* data */
    Employee* _employee;
    EmployeeList* _next;
public:
    EmployeeList(Employee* employee);
    void paycut(float a);
    void insert(Employee*);
    virtual ~EmployeeList ();
    friend ostream& operator<< (ostream& o, const EmployeeList& el);
};
#endif
