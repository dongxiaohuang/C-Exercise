#include "helper.h"
#include <iostream>
using namespace std;


int main()
{
  int n;
  cout << "please enter a number"<<endl;
  cin >> n;
  // cout << "the abs of the number of "<< n << " is "<< abs_num(n) << endl;
  cout << "The factorial of "<<n<<" is "<<factory(n)<< endl;
  return 0;
}
