#include "recursive.h"
#include <cstdlib>
#include <iostream>
using namespace std;
int factorial(int number)
{
  if(number < 0)
    {
      cout << "\nError - negative argument to factorial\n";
      exit(1);
    }
    else if(number == 1)
    {
      return 1;
    }else
    {
      return number*factorial(number - 1);
    }
}

int sum_of_list(int list[], int n)
{
  if(n == 1)
    return list[0];
  else
    return list[n-1] + sum_of_list(list, n-1);
}
