#ifndef COURSE_H
#define COURSE_H
#include <iostream>
using namespace std;

class Course {
private:
    /* data */
    const char* _name;
    const int _code;
public:
    Course (const char* name, const int code);
    int getCode() const;
    const char* getName() const;
    // virtual ~Course (){};
    friend ostream& operator<< (ostream& o, const Course* course);
};
#endif
