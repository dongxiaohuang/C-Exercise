#include "quicksort.h"
void swap(int &x, int &y)
{
  int z = x;
  x = y;
  y = z;
}
void quicksort(int list[], int left, int right)
{
  int left_arrow = left;
  int right_arrow = right;
  int pivot;
  int pivot_value;
  pivot = (left_arrow + right_arrow)/2;
  pivot_value = list[pivot];
  while(left_arrow <= right_arrow)
{
  while(list[left_arrow] < pivot_value)
  {
    left_arrow ++;
  }
  while(list[right_arrow] > pivot_value)
  {
    right_arrow --;
  }
  if(left_arrow <= right_arrow)
  {
    swap(list[right_arrow], list[left_arrow]);
    // do not forget
    left_arrow ++;
    right_arrow --;
  }
}
// do not forget
if(left < right_arrow)
  quicksort(list, left, right_arrow);
if(left_arrow < right)
  quicksort(list, left_arrow, right);

}
