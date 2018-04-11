#include "c1.h"
#include "c2.h"
#ifndef C3_H
#define C3_H
class c3{
  int num;
  c1 sub1;
  c2 sub2;
public:
  c3();
  c3(int );
  c3(int, int);
  ~c3();
};
#endif
