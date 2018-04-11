#ifndef TEST_H
#define TEST_H
#include <iostream>
using namespace std;
class Test{
  int id;
public:
  Test(int i);
  Test& operator=(const Test& t);
  friend ostream& operator<<(ostream& out, const Test& t);
  friend istream& operator>>(istream& in, Test& t);
  int operator()( int a, int b);
};

ostream& operator<<(ostream& out, const Test& t);
istream& operator>>(istream& in, Test& t);

#endif
