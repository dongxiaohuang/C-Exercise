#include "braille.h"
#include <cctype>
#include <cstring>

int encode_character(char ch, char* braille)
{
  char prefix[20] = "";
  int size;
  if(isalpha(ch))
  {
    if(isupper(ch))
      {
        strcpy(prefix, ".....0");
      }
    ch = tolower(ch);
    map(ch, braille);
  }
  else if(isdigit(ch))
  {
    strcpy(prefix, "..0000");
    if(ch != '0')
      ch = ch - '1' +'a' ;
    map(ch, braille);
  }else
  {
    map(ch, braille);
  }
  if(strcmp(prefix,"") != 0)
    {
      strcat(prefix, braille);
      strcpy(braille, prefix);
    }
  size = strlen(braille);
  return size;

}


void map(char ch, char* braille)
{
  switch (ch) {
    case 'a': strcpy(braille, "0....."); break;
		case 'b': strcpy(braille, "00...."); break;
		case 'c': strcpy(braille, "0..0.."); break;
		case 'd': strcpy(braille, "0..00."); break;
		case 'e': strcpy(braille, "0...0."); break;
		case 'f': strcpy(braille, "00.0.."); break;
		case 'g': strcpy(braille, "00.00."); break;
		case 'h': strcpy(braille, "00..0."); break;
		case 'i': strcpy(braille, ".0.0.."); break;
		case '0':
		case 'j': strcpy(braille, ".0.00."); break;
		case 'k': strcpy(braille, "0.0..."); break;
		case 'l': strcpy(braille, "000..."); break;
		case 'm': strcpy(braille, "0.00.."); break;
		case 'n': strcpy(braille, "0.000."); break;
		case 'o': strcpy(braille, "0.0.0."); break;
		case 'p': strcpy(braille, "0000.."); break;
		case 'q': strcpy(braille, "00000."); break;
		case 'r': strcpy(braille, "000.0."); break;
		case 's': strcpy(braille, ".000.."); break;
		case 't': strcpy(braille, ".0000."); break;
		case 'u': strcpy(braille, "0.0..0"); break;
		case 'v': strcpy(braille, "000..0"); break;
		case 'w': strcpy(braille, ".0.000"); break;
		case 'x': strcpy(braille, "0.00.0"); break;
		case 'y': strcpy(braille, "0.0000"); break;
		case 'z': strcpy(braille, "0.0.00"); break;
    // sign
    case '.': {strcpy(braille, ".0..00"); break;}
    case ',': {strcpy(braille, ".0...."); break;}
    case ';': {strcpy(braille, ".00..."); break;}
    case '-': {strcpy(braille, "..0..0"); break;}
    case '!': {strcpy(braille, ".00.0."); break;}
    case '?': {strcpy(braille, ".00..0"); break;}
    case '(':
    case ')': {strcpy(braille, ".00.00"); break;}
    default : {strcpy(braille, "ERROR"); break;}
  }
}
// if the braille doesnot clear then you need to use this helper function and set braille to ""
void encode_helper(const char* plaintext, char* braille)
{
  char braille_element[13];
  if(strcmp(plaintext,"") ==0)
  {}
  else
  {
    encode_character(plaintext[0], braille_element);
    strcat(braille, braille_element);
    encode_helper(++plaintext, braille);
  }
}
void encode(const char* plaintext, char* braille)
{
  char braille_element[13];
  if(strcmp(plaintext,"") ==0)
  {}
  else
  {
    encode_character(plaintext[0], braille_element);
    strcat(braille, braille_element);
    encode(++plaintext, braille);
  }
}

void print_braille(const char* plaintext, ostream& output)
{
  char braille[512] = "";
  encode(plaintext, braille);
  int size = strlen(braille);
  int height = 3;
  int width = (size / height)/2 *3;
  // int width = (size / height);
  char b_array[height][width];
  // cout << height << " h-w " <<width << endl;
  int index = 0;
  // cout << "braille" << braille << endl;
  // cout << "______======_____" << endl;
  for(int w = 0; w < width; w ++)
  {
    for(int h = 0; h < height; h++)
    {
      if(w%3 == 2)
      {
        b_array[h][w] = ' ';
      }else
      {
        b_array[h][w] = braille[index];
        index++;
      }
    }
  }
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      output << b_array[i][j];
    }
    output << endl;
  }
  while(strcmp(plaintext,"") != 0)
  {
    if(isupper(plaintext[0]) ||isdigit(plaintext[0]))
      output << "   ";
    output<<plaintext[0]<<"  ";
    plaintext++;
  }
}
