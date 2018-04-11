#include <iostream>
#include "help.h"
using namespace std;

int main()
{
  auto i = 2;
  // lvalue reference
  int &i_l_ref = i;
  //it is wrong to int &i = 2;

  // rvalue reference
  /**
  * no name and no address
  */
  int &&r_ref = 3+4;

  /* initialization */
  int a[]{1,2,3};
  // int &&res = sum_arr(a);
  // you cannot use : in the function
  cout << res;
  for(auto e:a)
  {
    cout << e << " ";
  }
  cout << endl;

  int x = 3+5;
  int y{3+5};
  int z(3+5);

  int *ii = new int(3);
  cout << *ii<<endl;
  delete ii;

  float *ee = new float{1.2f};
  cout << *ee << endl;
  delete ee;

  /* type declaration */
  struct{
    char *name;
  } anon_u;
  struct{
    int d;
    decltype(anon_u) id;
  }anon_s[4];

    decltype(anon_s) e;
    // cout << "please input the name :" <<endl;
    // cin >> e[0].id.name;
}
