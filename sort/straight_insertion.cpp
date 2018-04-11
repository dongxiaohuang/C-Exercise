#include "straight_insertion.h"
#include "helper.h"
// performance better than simple_selection
void straight_insertion_sort(int list[], int len)
{
  int tmp;
  for(int i = 1; i < len; i++)
  {
    if(list[i] < list[i-1])
    {
      tmp = list[i];
      int j;
      for( j = i; list[j-1]>tmp; j--)
      {
        list[j] = list[j-1];
      }
      list[j] = tmp;
    }
  }
}
