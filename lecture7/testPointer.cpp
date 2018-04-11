#include "testPointer.h"

void test1(char *a)
{
  a[0] = 'a';
  a++;
}
// work the same test1 and test3
// change the value but not change the address of the point pointed to
void test2(char * &a)
{
  a[0] = 'a';
  a++;
}
// change the value and the address the point pointed to
void test3(char a[])
{
  a[0] = 'a';
  a++;
}
