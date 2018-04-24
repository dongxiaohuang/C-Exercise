#include "Course.h"

Course::Course(const char* name, const int code):
    _name(name), _code(code){}

int Course::getCode() const{ return _code;}
const char* Course::getName() const{ return _name;}
ostream& operator<< (ostream& o, const Course* course){
    return o << "Course " << course -> getCode() <<": "
        << course -> getName() << endl;
}
