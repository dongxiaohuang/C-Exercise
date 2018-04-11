#include "soundex.h"
#include <cctype>
#include <iostream>
using namespace std;
void encode(const char surname[], char soundex[])
{
  const char * ptr;
  int encoded_index = 0;
  //initiliaze the soundex[4]
  for (int i = 0; i < 4; i++) {
    soundex[i] = '0';
  }
  ptr = surname;
  // encode first index
  if(isalpha(*ptr))
    {soundex[encoded_index] =(char) toupper(*ptr);
    encoded_index ++;}
  else
  {
    cout << "wrong input the first character is not alpha" << endl;
    exit(1);
  }
  ptr++;
  while(encoded_index < 4 && ptr[0] != '\0')
  {
  char coded_ch;
  coded_ch = encode_ch(ptr[0]);
  if(coded_ch != '#' && encoded_index <= 4)
    {
      if(coded_ch != soundex[encoded_index - 1])
      {
        soundex[encoded_index] = coded_ch;
        encoded_index++;
      }
    }
    ptr++;
  }
  soundex[4] ='\0';
}

char encode_ch(char ch)
{
  switch (ch)
   {
    case 'b':
    case 'f':
    case 'p':
    case 'v': {return '1'; break;}
    case 'c':
    case 'g':
    case 'j':
    case 'k':
    case 'q':
    case 's':
    case 'x':
    case 'z': {return '2'; break;}
    case 'd':
    case 't': {return '3'; break;}
    case 'l': {return '4'; break;}
    case 'm':
    case 'n': {return '5'; break;}
    case 'r': {return '6'; break;}
    default: return '#';
  }
}

bool compare(const char *s1, const char *s2)
{
  int flag = 1;
  if(s1[0] == '\0' && s2[0] == '\0')
   return true;
  else if(s1[0] != s2[0])
   return false;
  else
    return flag*compare(++s1, ++s2);
}

int count(const char surname[], const char sentence[])
{
  char ref_soundex[5];
  encode(surname, ref_soundex);
  // ref_soundex[4] = '\0';
  char *tok_ptr;
  int count = 0;
  char sen_ptr[200];
  strcpy(sen_ptr,sentence);
  tok_ptr = strtok(sen_ptr ,",. ");
  while (tok_ptr != NULL) {
    if(strcmp(tok_ptr,"and") == 0)
      {
        tok_ptr = strtok(NULL, ",. ");
        continue;
      }
    char another_soundex[5]; // must be 5
    encode(tok_ptr, another_soundex);
    // cout << "---------------" << endl;
    // cout << "another_soundex " << another_soundex << endl;
    // cout << "---------------" << endl;
    if(compare(ref_soundex, another_soundex))
      {count ++;}
    tok_ptr = strtok(NULL, ",. ");
  }
  return count;
}
