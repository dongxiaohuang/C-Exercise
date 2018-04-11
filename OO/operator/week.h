#ifndef WEEK_H
#define WEEK_H

#include <cstring>
const char WEEK_NAME[7][4]{"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};

class WeekTemp
{
 int temp[7];
public:
 int& operator[](const char *);
 // the return type must be a reference only when you
 // need to change the value of it
 // so stream/ =/[] can be return reference
 // if it is not reference then the [] can only be a
 // rvalue
};

#endif
