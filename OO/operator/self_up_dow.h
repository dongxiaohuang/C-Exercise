#ifndef SELF_UP_DOW_H
#define SELF_UP_DOW_H
#include <iostream>
using namespace std;
class Up
{
  int index;
public:
  Up(int i) : index(i){}
  friend ostream& operator<<(ostream& out, const Up );
  Up operator++();
  Up operator++(int dummy); // posterior add a dummy int
};

ostream& operator<<(ostream& out, const Up );

#endif
