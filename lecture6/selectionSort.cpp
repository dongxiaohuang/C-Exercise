#include "selectionSort.h"

void swap(int &x, int &y)
{
  int z = x;
  x = y;
  y = z;
}
void selectionSort(int list[], int length)
{
  for(int i = 0; i < length-1; i ++)
  {
    for(int j = i+1; j <= length -1; j ++)
    {
      if(list[j] < list[i])
       swap(list[j],list[i]);
    }
  }
}
