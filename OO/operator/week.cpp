#include "week.h"

int& WeekTemp::operator[](const char * name)
{
  for(int i =0; i <7; i++)
  {
    if(strcmp(name, WEEK_NAME[i]) == 0)
    {
      return temp[i];
    }
  }
  // return temp[0];
}
