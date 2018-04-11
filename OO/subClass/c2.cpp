#include "c2.h"

c2::c2():num(0)
{
  cout << "c2()" << endl;
}
c2::c2(int id=0):num(id)
{
  cout << "c2()" << endl;
}
/**
 *
 c2.cpp:3:12: error: addition of default argument on redeclaration makes this constructor a default constructor
c2::c2(int id = 0):num(id)
           ^    ~
./c2.h:9:3: note: previous declaration is here
  c2(int id);
 */

c2::~c2()
{
  cout << "~c2()"<<endl;
}
