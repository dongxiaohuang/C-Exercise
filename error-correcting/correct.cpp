#include <iostream>
#include <cstring>
using namespace std;

/* You are supplied with two helper functions */

/* converts a character into a binary string representation */
void ascii_to_binary(char ch, char *binary);

/* converts a binary string representation into a character */
char binary_to_ascii(const char *binary);

void ascii_to_binary(char ch, char *binary) {
  for (int n = 128; n; n >>= 1)
    *binary++ = (ch & n) ? '1' : '0';
  *binary = '\0';
}

char binary_to_ascii(const char *binary) {
  int ch = 0;
  for (int n=0, slide=128; n<8; n++, slide >>= 1) {
    if (binary[n] == '1')
      ch = ch | slide;
  }
  return ch;
}

/* now add your own functions here */
void text_to_binary_helper(const char* sentence, char binary[])
{
  char binary_element[9];
  if(sentence[0] == '\0')
  {}else{
    ascii_to_binary(sentence[0], binary_element);
    sentence++;
    strcat(binary, binary_element);
    text_to_binary_helper(sentence, binary);
  }
}
void text_to_binary(const char* sentence, char binary[])
{
  strcpy(binary, "");
  text_to_binary_helper(sentence, binary);
}
void binary_to_text_helper(const char* binary, char text[])
{
  char binary_cp[512];
  char ch[2];
  strcpy(binary_cp, binary);
  char *binary_ptr = binary_cp;
  if(binary_ptr[0] != '\0')
  {
    // try use strncpy
    *(binary_ptr +8) = '\0';
    ch[0] = binary_to_ascii(binary_cp);
    ch[1] = '\0';
    strcat(text, ch);
    strcpy(binary_cp, binary);
    binary_ptr = binary_cp + 8;
    binary_to_text_helper(binary_ptr, text);
  }
}
void binary_to_text(const char* binary, char text[])
{
  strcpy(text, "");
  binary_to_text_helper(binary, text);
}

char parity(char d1, char d2, char d3)
{
  if(d1 == '0' && d2 == '0' && d3 == '0')
    return '0';
  if(d1 == '0' && d2 == '1' && d3 == '1')
    return '0';
  if(d1 == '1' && d2 == '0' && d3 == '1')
    return '0';
  if(d1 == '1' && d2 == '1' && d3 == '0')
    return '0';
  return '1';
}

void add_error_correction_helper(const char* data, char corrected[])
{
  char data_cp[512];
  char *data_ptr;
  char c1, c2, c3;
  char code_elem[8];
  strcpy(data_cp,data);
  data_ptr = data_cp;
  if(strlen(data) % 4 != 0)
    {cout << "error number of bits "; return;}
  if(data_ptr[0] != '\0')
  {
    // initial corrceted;???
    c1 = parity(data_ptr[0], data_ptr[1], data_ptr[3]);
    c2 = parity(data_ptr[0], data_ptr[2], data_ptr[3]);
    c3 = parity(data_ptr[1], data_ptr[2], data_ptr[3]);

    code_elem[0] = c1;
    code_elem[1] = c2;
    code_elem[2] = data_ptr[0];
    code_elem[3] = c3;
    code_elem[4] = data_ptr[1];
    code_elem[5] = data_ptr[2];
    code_elem[6] = data_ptr[3];
    code_elem[7] = '\0';

    strcat(corrected, code_elem);
    data_ptr = data_ptr + 4;
    add_error_correction_helper(data_ptr, corrected);

  }
}
void add_error_correction(const char* data, char corrected[])
{
  strcpy(corrected,"");
  add_error_correction_helper(data, corrected);
}



int char_to_int(char num)
{
  int digit;
  digit = num - '0';
  return digit;
}

char parity(char d1, char d2, char d3, char d4)
{
  int dd1, dd2, dd3, dd4;
  dd1 = char_to_int(d1);
  dd2 = char_to_int(d2);
  dd3 = char_to_int(d3);
  dd4 = char_to_int(d4);
  return ((dd1 + dd2 + dd3 + dd4)%2)? '1':'0';

}

int erro_position_map(char *position)
{
  if(strcmp(position, "001") == 0)
    return 1;
  if(strcmp(position, "010") == 0)
    return 2;
  if(strcmp(position, "011") == 0)
    return 3;
  if(strcmp(position, "100") == 0)
    return 4;
  if(strcmp(position, "101") == 0)
    return 5;
  if(strcmp(position, "110") == 0)
    return 6;
  if(strcmp(position, "111") == 0)
    return 7;
  return -1; // error
}
char flip(char ch)
{
  return (ch == '0') ? '1':'0';
}
void decode_helper(const char* received, char decoded[], int &count)
{
  char p1, p2, p3;
  char erro_position[4];
  char received_cp[512];
  char dec_ele[5];
  int err_pos_index;
  strcpy(received_cp, received);
  char *rec_ptr = received_cp;
  if(rec_ptr[0] != '\0')
  {
    p1 = parity(rec_ptr[3], rec_ptr[4], rec_ptr[5], rec_ptr[6]);
    p2 = parity(rec_ptr[1], rec_ptr[2], rec_ptr[5], rec_ptr[6]);
    p3 = parity(rec_ptr[0], rec_ptr[2], rec_ptr[4], rec_ptr[6]);
    if(p1 != '0' || p2 != '0' || p3 != '0')
    {
      count ++;
      erro_position[0] = p1;
      erro_position[1] = p2;
      erro_position[2] = p3;
      erro_position[3] = '\0';
      err_pos_index = erro_position_map(erro_position);
      rec_ptr[err_pos_index - 1] = flip(rec_ptr[err_pos_index - 1]);
    }
    // get element
      dec_ele[0] = rec_ptr[2];
      dec_ele[1] = rec_ptr[4];
      dec_ele[2] = rec_ptr[5];
      dec_ele[3] = rec_ptr[6];
      dec_ele[4] = '\0';
      strcat(decoded, dec_ele);
      rec_ptr = rec_ptr +7;
      decode_helper(rec_ptr, decoded, count);
  }
}
int decode(const char* received, char decoded[])
{
  strcpy(decoded,"");
  int count = 0;
  decode_helper(received, decoded, count);
  return count;
}
