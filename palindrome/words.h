#ifndef WORDS_H
#define WORDS_H
const int MAX_SIZE = 200;
void reverse(const char str1[], char *str2);
bool compare(const char*, const char*);
bool palindrome(const char* sentence);
bool anagram(const char*, const char*);
void sort_str(char str1[]);
void swap(char &x, char &y);
#endif
