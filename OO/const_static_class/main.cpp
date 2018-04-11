#include <iostream>
#include "helper.h"
using namespace std;

int main()
{
  Helper h1(2088);
  Helper h2(2009);
  cout << "current number of helpers are :" << Helper::getNum()<<endl;
  cout << "the ID of h1 is "<< h1.getID() << endl;
  cout << "the ID of h2 is "<< h2.showId() << endl;
  const Helper h3(2018);
  cout << "the ID of h3 is "<< h3.getID() << endl;
  // cout << "the ID of h3 is "<< h3.showId() << endl;
  // const class object can only use const function
  cout << "current number of helpers are :" << Helper::getNum()<<endl;

  return 0;
}
