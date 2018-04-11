#ifndef CORRECT_H
#define CORRECT_H

void ascii_to_binary(char letter, char *output); // 8bits
char binary_to_ascii(const char *binary); //8bits
void text_to_binary(const char* sentence, char binary[]);
void binary_to_text(const char* binary, char text[]);
void add_error_correction(const char* data, char corrected[]);
char parity(char d1, char d2, char d3);
char parity(char d1, char d2, char d3, char d4);
int decode(const char* received, char decoded[]);
int char_to_int(char num);
int erro_position_map(char *);
char flip(char ch);
#endif
