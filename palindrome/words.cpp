#include "words.h"
#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;
void reverse(const char str1[], char *str2)
{
  int len;
  len = strlen(str1);
  for (int i = len - 1; i >= 0; i--) {
     int j = len - 1 -i;
     str2[j] = str1[i];
  }
  str2[len] = '\0';
}

bool compare(const char* str_one, const char* str_two)
{
  if(str_one[0] =='\0' && str_two[0] =='\0')
    return true;
  else if(isalpha(str_one[0]) && isalpha(str_two[0]))
    {
      if(toupper(str_one[0]) != toupper(str_two[0]))
        return false;
      else
        return compare(++str_one, ++str_two);
    }
  else if(isalpha(str_one[0]) && !isalpha(str_two[0]))
    {
      while(!isalpha(str_two[0]))
        {
          str_two++;
        }
      if(toupper(str_one[0]) != toupper(str_two[0]))
          return false;
      else
        return compare(++str_one, ++str_two);
    }
  else if(!isalpha(str_one[0]) && isalpha(str_two[0]))
    {
      while(!isalpha(str_one[0]))
        {
          str_one++;
        }
      if(toupper(str_one[0]) != toupper(str_two[0]))
          return false;
      else
          return compare(++str_one, ++str_two);
    }
  else if(!isalpha(str_one[0]) && !isalpha(str_two[0]))
    {
      const char * next_one = str_one +1;
      const char * next_two = str_two +1;
      while(!isalpha(str_one[0]))
        {
          str_one++;
          if(*str_one =='\0')
            {next_one = str_one; break; }
        }
      while(!isalpha(str_two[0]))
        {
          str_two++;
          if(*str_two =='\0')
            { next_two = str_two; break;}
        }
      if(toupper(str_one[0]) != toupper(str_two[0]))
          return false;
      else
          return compare(next_one, next_two);
    }

}

bool palindrome(const char * sentence)
{
  char revered_sentence[MAX_SIZE];
  reverse(sentence, revered_sentence);
  return compare(sentence, revered_sentence);
}

void swap(char &x, char &y)
{
  char z;
  z = x;
  x = y;
  y = z;
}

void sort_str(char str[])
{

  int n = strlen(str);
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j <= n-1; j++) {
      if(toupper(str[j]) < toupper(str[i]))
        swap(str[j], str[i]);
    }
  }
}
bool anagram(const char* str1, const char* str2)
{
  //copy str1
  char str_1[MAX_SIZE];
  strcpy(str_1, str1);
  //copy str2
  char str_2[MAX_SIZE];
  strcpy(str_2, str2);

  // pre process the string
  sort_str(str_1);
  sort_str(str_2);
  return compare(str_1, str_2);

}
