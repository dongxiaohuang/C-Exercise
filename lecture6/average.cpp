#include "average.h"
float average(int hours[], int length)
{
  float res;
  float sum = 0;
  for(int i = 0; i < length; i++)
  {
    sum += hours[i];
  }
  res = (float)sum/length;
  return res;
}
