#include "helper.h"
#include "shell_sort.h"

void shell_sort(int list[], int len)
{
  int i;
  int increment = len;
  do {
    // almost sort
    increment = increment/3 +1;
    for(i = increment; i < len; i++)
    {
      if(list[i-increment] > list[i])
        swap(list[i-increment],list[i]);
    }
  } while(increment > 1);
}
