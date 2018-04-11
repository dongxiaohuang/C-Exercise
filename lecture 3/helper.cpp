#include "helper.h"
int abs_num(int n)
{
  if(n >= 0)
    return n;
  else return -n;
}

int fact(int n)
{
  int res;
  if(n == 1)
   res = 1;
  else
   {
     res = n * fact(n-1);
   }
   return res;
}
int factory(int n)
{
  int res = 1;
  for(int i = 1; i <=n; i ++)
   res *= i;
  return res;
}
