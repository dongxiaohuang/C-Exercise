#ifndef PIGLATIN_H
#define PIGLATIN_H
#include <iostream>
using namespace std;
bool isVowel(char ch, int position, int length);
int findFirstVowel(const char *);
void translateWord(const char* english, char * piglatin);
void translateStream(istream& inputStream, ostream& outputStream);
#endif
