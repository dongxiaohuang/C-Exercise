#include "helper.h"
#include "quick_sort.h"

void quick_sort(int list[], int left, int right)
{
  int left_arrow = left;
  int right_arrow = right;
  int pivot_index = (right+left)/2;
  while(left_arrow < right_arrow)
  {
    while(list[left_arrow] < list[pivot_index])
      left_arrow ++;
    while(list[right_arrow] > list[pivot_index])
      right_arrow --;
    if(list[right_arrow] <= list[left_arrow])
      {
        swap(list[right_arrow] , list[left_arrow]);
        left_arrow++;
        right_arrow--;
      }
  }
  // while(left < right_arrow) // cannot use while
  if(left < right_arrow) // cannot use while
  {
    quick_sort(list,left, right_arrow);
  }
  // while(right > left_arrow) // cannot use while
  if(right > left_arrow) // cannot use while
  {
    quick_sort(list,left_arrow, right);
  }


}
