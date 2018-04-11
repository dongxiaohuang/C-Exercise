#include "c3.h"

// c3::c3():num(1),c1(123){ //ERROR : must use obj name
c3::c3():num(1),sub1(123){
  cout << "c3"<<endl;
}
c3::c3(int n):num(n),sub1(123){
  cout << "c3"<< endl;
}
c3::c3(int n, int n1):num(n),sub1(n1)
{
  cout << "c3"<< endl;
}
c3::~c3()
{
  cout << "c3" <<endl;
}
