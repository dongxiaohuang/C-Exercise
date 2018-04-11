#include "info.h"
#include <iostream>
using namespace std;
// constructor and destructor
int main()
{
  Info ts;
  ts.print();
  Info ts2 (11);
  ts2.print();
  Info ts3(ts2);
  ts3.print();
  func3();
  change_i_val(100, ts);
  ts.print();
  return 0;
}
