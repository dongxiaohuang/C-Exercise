#include "substring.h"
#include <iostream>
#include <cstring>
using namespace std;
int substring_position(const char word[], const char sentence[])
{
  const char *ptr_sen = sentence;
  int index = 0;
  if(strcmp(word,"") == 0)
    return 0;

  while(strcmp(ptr_sen, "") != 0)
  {
    if(is_prefix(word, ptr_sen))
      break;
    index ++;
    ptr_sen ++; // every time it will change as well so do not use ptr_sen += index
  }
  if(strcmp(ptr_sen, "") == 0)
    return -1;
  return index;
}

bool is_prefix(const char word[], const char sentence[])
{
  const char *ptr;
  const char *ptr_sen;
  ptr = word;
  ptr_sen = sentence;
  while(strcmp(ptr,"") != 0)
  // while(*ptr_sen != '\0')
  {
    if(*ptr != * ptr_sen)
      {
        return false;
      }
    ptr_sen++;
    ptr++;
  }
  return true;
}
