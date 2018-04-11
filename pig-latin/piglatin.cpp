#include "piglatin.h"
#include <cctype>
#include <cstring>

bool isVowel(char ch, int position, int length)
{
  if(ch =='a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    return true;
  if(ch == 'y' && position != 0 && position != length - 1)
    return true;
  return false;
}

int findFirstVowel(const char * sentence)
{
  int length = strlen(sentence);
  int index = 0;
  while(sentence[index] != '\0')
  {
    if(isVowel(sentence[index], index, length))
      break;
    index ++;
  }
  if(sentence[index] == '\0')
    return -1;
  return index;
}

void translateWord(const char* english, char * piglatin)
{
  int uppercase_flg = 0;
  int index_first_vowel;
  char english_cpy[200];
  strcpy(english_cpy, english);
  if(isalnum(english[0]))
  {
    // if is alpaha
    if(isalpha(english_cpy[0]))
    {
      if(isupper(english_cpy[0]))
       {
         // pre process all the letters are lower case
          uppercase_flg = 1;
          english_cpy[0] = tolower(english_cpy[0]);
       }
      index_first_vowel = findFirstVowel(english_cpy);
      // no vowel
      if(index_first_vowel == -1)
        {
          strcpy(piglatin, english_cpy);
          strcat(piglatin, "ay");
        }
      else if(index_first_vowel == 0)
        {
          strcpy(piglatin, english_cpy);
          strcat(piglatin, "way");
        }
      else
      {
        char first_part[200];
        char *english_cpy_ptr;
        english_cpy_ptr = english_cpy;
        strcpy(first_part, english_cpy);
        first_part[index_first_vowel] = '\0';
        english_cpy_ptr = english_cpy_ptr + index_first_vowel;
        strcat(first_part, "ay");
        strcat(english_cpy_ptr, first_part);
        strcpy(piglatin, english_cpy_ptr);
      }
      // post process capital
      if(uppercase_flg == 1)
      {
        piglatin[0] = toupper(piglatin[0]);
      }
    }else
    // digital
    {
      strcpy(piglatin, english);
    }
  }else
  {
    strcpy(piglatin,"");
  }
}

void translateStream(istream& inputStream, ostream& outputStream)
{
  char words[65];
  char translated[100];
  char pre_symbol[2] = "";
  char pos_symbol[2] = "";
  inputStream >> words;
  char * words_ptr = words;
  int len = strlen(words);

  if(inputStream.eof())
  {}
  else
  {
    // pre process words:
    if(!isalnum(words[0]))
    {
      pre_symbol[0] = words[0];
      pre_symbol[1] = '\0';
      words_ptr++;
    }
    // pre process words:
    if(!isalnum(words[len-1]))
    {
      pos_symbol[0] = words[len-1];
      pos_symbol[1] = '\0';
      words_ptr[len-1] = '\0';
    }
    translateWord(words_ptr, translated);
    if(strcmp(pos_symbol,"") == 0)
      outputStream<< pre_symbol << translated<<  " ";
    else
    outputStream<< pre_symbol << translated<< pos_symbol << endl;
    translateStream(inputStream, outputStream);
  }
}
// more elegent way
// void translateStream(istream& in, ostream& out) {
//
// 	char english[65], piglatin[65];
// 	char ch;
//
// 	if (in.get(ch)) {
//
// 		if (isalnum(ch)) {
// 			in.putback(ch);
// 			in >> english;
// 			translateWord(english, piglatin);
// 			out << piglatin;
// 		} else {
// 			out << ch;
// 		}
//
// 		translateStream(in, out);
// 	} else {
// 		out << endl;
// 	}
// }
