#include <iostream>
#include "quicksort.h"
#include "recursive.h"
using namespace std;

int main()
{
  int list[] = {3,4,2,46,0,7,3,4,13};
  cout << " before quicksort " <<endl;
  for(int i =0; i < 9; i++)
    cout << list[i] << " " ;
    cout << endl;

  quicksort(list, 0, 8);
  cout << " after quicksort" << endl;
  for(int i =0; i < 9; i++)
    cout << list[i] << " < " ;
    cout << endl;

    cout << "please try factorial"<< endl;
    int n;
    cin >> n;
    cout << "the result is : " << factorial(n) << endl;
  return 0;
}
