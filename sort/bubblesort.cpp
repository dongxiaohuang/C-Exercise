#include "helper.h"
#include "bubblesort.h"

void bubblesort1(int list[], int len)
{
  for (int i = 0; i < len-1; i++)
  {
    for (int j = len-1; j > i; j--)
    {
      if(list[j] < list[j-1])
        swap(list[j], list[j-1]);
    }
  }
}

void bubblesort_impr(int list[], int len)
{
  bool hasExchange = true;
  for(int i =0; i < len -1 && hasExchange; i++)
  {
    hasExchange = false;//initial to false
    //no  unorder sequence·
    for(int j = len-1; j > i; j--)
    {
      if(list[j] < list[j-1])
        {
          swap(list[j], list[j-1]);
          hasExchange = true;
        }
    }
  }
}
