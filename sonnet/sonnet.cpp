#include <iostream>
#include <cstring>
#include <cctype>
#include <cassert>
#include <map>
#include <string>
#include <fstream>

using namespace std;

#include "sonnet.h"

/* PRE-SUPPLIED HELPER FUNCTIONS START HERE */

/* NOTE: It is much more important to understand the interface to and
   the "black-box" operation of these functions (in terms of inputs and
   outputs) than it is to understand the details of their inner working. */

/* get_word(...) retrieves a word from the input string input_line
   based on its word number. If the word number is valid, the function
   places an uppercase version of the word in the output parameter
   output_word, and the function returns true. Otherwise the function
   returns false. */

bool get_word(const char *input_line, int word_number, char *output_word) {
  char *output_start = output_word;
  int words = 0;

  if (word_number < 1) {
    *output_word = '\0';
    return false;
  }

  do {
    while (*input_line && !isalnum(*input_line))
      input_line++;

    if (*input_line == '\0')
      break;

    output_word = output_start;
    while (*input_line && (isalnum(*input_line) || *input_line=='\'')) {
      *output_word = toupper(*input_line);
      output_word++;
      input_line++;
    }
    *output_word = '\0';

    if (++words == word_number)
      return true;

  } while (*input_line);

  *output_start = '\0';
  return false;
}

/* char rhyming_letter(const char *ending) generates the rhyme scheme
   letter (starting with 'a') that corresponds to a given line ending
   (specified as the parameter). The function remembers its state
   between calls using an internal lookup table, such that subsequents
   calls with different endings will generate new letters.  The state
   can be reset (e.g. to start issuing rhyme scheme letters for a new
   poem) by calling rhyming_letter(RESET). */

char rhyming_letter(const char *ending) {

  // the next rhyming letter to be issued (persists between calls)
  static char next = 'a';
  // the table which maps endings to letters (persists between calls)
  static map<string, char> lookup;

  // providing a way to reset the table between poems
  if (ending == RESET) {
    lookup.clear();
    next = 'a';
    return '\0';
  }

  string end(ending);

  // if the ending doesn't exist, add it, and issue a new letter
  if (lookup.count(end) == 0) {
    lookup[end]=next;
    assert(next <= 'z');
    return next++;
  }

  // otherwise return the letter corresponding to the existing ending
  return lookup[end];
}

/* START WRITING YOUR FUNCTION BODIES HERE */
int count_words(const char *line)
{
  char line_cpy[512];
  strcpy(line_cpy, line);
  char * tok_ptr;
  int size = 0;
  tok_ptr = strtok(line_cpy, " -");
  while(tok_ptr != NULL)
  {
    size++;
    tok_ptr = strtok(NULL, " -");
  }
  return size;
}
bool has_vowel(const char *word)
{
  int len;
  len = strlen(word);
  for(int i = 0; i < len; i++)
  {
    if(tolower(word[i]) == 'a' || tolower(word[i]) == 'e' || tolower(word[i]) == 'i' || tolower(word[i]) == 'o' || tolower(word[i]) == 'u')
      return true;
  }
  return false;
}

bool find_phonetic_ending(const char *word, char phonetic_ending[])
{
  ifstream instream;
  char dictionary_line[512];
  char dictionary_words[512];
  int index = 1;
  instream.open("dictionary.txt");
  if (instream.fail())
		{
			cout << "Sorry, the dictionary file couldn't be opened!\n";
			exit(1);
		}
  instream.getline(dictionary_line, 512);
  while (!instream.eof()) {
    get_word(dictionary_line, 1, dictionary_words);
    if(strcmp(dictionary_words, word) == 0)
      {break;}
    instream.getline(dictionary_line, 512);
  }
  if(instream.eof())
  {
    strcpy(phonetic_ending, "ERROR");
    return false;
  }
  instream.close();
  while(get_word(dictionary_line, index, dictionary_words))
    {
      if(has_vowel(dictionary_words))
      {
        // strcpy(phonetic_ending,"");
        strcpy(phonetic_ending, dictionary_words);
      }
      else
      {
        strcat(phonetic_ending, dictionary_words);
      }
      index ++;
    }
  return true;
}

bool find_rhyme_scheme(const char *filename, char scheme[])
{
  ifstream in_stream;
  in_stream.open(filename);
  char poem_line[512];
  int index = 0;
  if(in_stream.fail())
  {
    cout << "cannot open file " << filename << endl;
    return false;
  }
  rhyming_letter(RESET);
  in_stream.getline(poem_line, 512);
  while(!in_stream.eof())
  {
    char endings[128];
    char endings_ph[128];
    int ending_idx = count_words(poem_line);
    get_word(poem_line, ending_idx, endings);
    if(!find_phonetic_ending(endings, endings_ph))
      return false;
    scheme[index] = rhyming_letter(endings_ph);
    index ++;
    in_stream.getline(poem_line,512);
  }
  in_stream.close();
  scheme[index] = '\0';
  return true;
}
char* identify_sonnet(const char *filename)
{
  char* style = new char[20];
  strcpy(style, "Unknown");
  char reference_scheme[512];
  char shakespeare_scheme[512];
  char petrarchan_scheme[512];
  char spenserian_scheme[512];
  find_rhyme_scheme("shakespeare.txt", shakespeare_scheme);
    // cout << "The rhyme scheme of shakespeare.txt do not exist " << endl;
  find_rhyme_scheme("petrarch.txt", petrarchan_scheme);
    // cout << "The rhyme scheme of petrarch.do not exist"<< endl;
  find_rhyme_scheme("spenser.txt", spenserian_scheme);
    // cout << "The rhyme scheme of spenser.txt not exist"<< endl;
  find_rhyme_scheme(filename, reference_scheme);
    // cout << "The rhyme scheme of "<<filename<<"not exist"<< endl;
  if(strcmp(reference_scheme, shakespeare_scheme) == 0)
      strcpy(style, "Shakespean");
  if(strcmp(reference_scheme, petrarchan_scheme) == 0)
      strcpy(style, "Petrarchan");
  if(strcmp(reference_scheme, spenserian_scheme) == 0)
      strcpy(style, "Spenserian");

  return style;
}
