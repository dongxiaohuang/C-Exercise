#include "heap_sort.h"
#include "helper.h"
// O(nlogn)
void heap_sort(int list[], int len)
{
  heap_adjust(list, len);
  // start to get the
  while(len >= 2)
  {
    swap(list[0], list[len-1]);
    len --;
    heap_adjust(list, len);
  }

}

void heap_adjust(int list[], int len)
{
  int parent_node_num = len/2 - 1;
  // initial the heap
  for(int i = parent_node_num; i >= 0; --i)
  {
    int max_child_index = 2*i + 1;
    if(2*i+2 <= len - 1 && list[2*i+2] > list[max_child_index])
      max_child_index = 2*i + 2;
    if(list[max_child_index] > list[i])
      swap(list[max_child_index],list[i]);
  }
}
