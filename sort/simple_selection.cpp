#include "helper.h"
#include "simple_selection.h"

// effiency is better than bubblesort
void simple_selection_sort(int list[],  int len)
{
  int min_index;

  for(int i = 0; i < len-1; i++)
  {
    min_index = i;
    for(int j = i+1; j < len; j++)
    {
      if(list[j] < list[min_index])
        min_index = j;
    }

  if(min_index != i)
    swap(list[i],list[min_index]);
  }
}
