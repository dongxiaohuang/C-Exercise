#ifndef SOUNDEX_H
#define SOUNDEX_H

void encode(const char surname[], char soundex[]);
char encode_ch(char ch);
bool compare(const char *s1, const char *s2);
int count(const char surname[],const char sentence[]);

#endif
