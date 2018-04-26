#ifndef AF_H
#define AF_H
#include <string>
#include <iostream>
using namespace std;
class AF {
private:
     /* data */
     string _name;
     int _year;
protected:
     float _os_mark;
public:
     AF (string name, int year, float os_mark);
     virtual float calculateScore() = 0;
};
#endif
