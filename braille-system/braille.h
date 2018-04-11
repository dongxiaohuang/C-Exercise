#ifndef BRAILLE_H
#define BRAILLE_H
#include <iostream>
using namespace std;
int encode_character(char ch, char* braille);
void map(char ch, char* code);
void encode(const char * plaintext, char * braille);
void print_braille(const char* plaintext, ostream& output);
#endif
