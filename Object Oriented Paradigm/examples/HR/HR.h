#ifndef HR_H
#define HR_H
#include <string>
#include <stack>
#include "AF.h"
class HR {
private:
     /* data */
     int _size;
     stack<AF*> tray;
     int _year_of_birth;
     string _name;
public:
     HR (string name, int year, int size);
     bool receive(AF* af);
     int count() const;
     void remove();
};
#endif
