#include <iostream>
#include <fstream>
#include "average.h"
#include "selectionSort.h"
using namespace std;

const int MAX_LENGTH = 1000;
// const int NO_OF_EMPLOYEES = 6;
typedef char File_array[MAX_LENGTH];
enum Logical {False, True};
const int SCREEN_HEIGHT = 449;
const int SCREEN_WIDTH = 639;
void clear_bitmap(Logical map[][SCREEN_WIDTH],int screen_len);
int main()
{
  int index = 0;
  File_array file;
  ifstream in_file;
  in_file.open("main.cpp");
  in_file.get(file[0]);
  for(int count = 1; !in_file.eof() && count < MAX_LENGTH; count ++ )
  {·
    in_file.get(file[count]);
  }
  in_file.close();
  while(file[index] != '\0')
  {
    cout << file[index];
    index++;
  }
//  -------------------
  // int hours[NO_OF_EMPLOYEES];
  // int count;
  // for (count = 1 ; count <= NO_OF_EMPLOYEES ; count++)
	// 	{
	// 		cout << "Enter hours for employee number " << count << ": ";
	// 		cin >> hours[count - 1];
	// 	}
  //   cout << endl;
  // cout << "the average hours of the employees are :" << average(hours, NO_OF_EMPLOYEES) << endl;
  // ------------
  int list[9] = {1,2,3,5,3,5,7,100,2};
  selectionSort(list, 9);
  for(int i =0; i <9; i++)
  cout << list[i]<<" - ";
  cout << endl;
  //----------------

  Logical screen[SCREEN_HEIGHT][SCREEN_WIDTH];
  screen[3][1] = True;
  clear_bitmap(screen, SCREEN_HEIGHT);
  cout << screen[3][1] << endl;
  //-------------
  // string illustration

  cout << "Enter first string: ";
  char first_str[80];
  cin.getline(first_str, 80);
  cout << "Enter second string: ";
  char second_str[80];
  cin.getline(second_str, 80);
  if(strcmp(first_str, second_str) == 0)
  {
    cout << "Before copying the strings were the same.";
    cout << "After concatenating, the first string is: "<< first_str<< endl;
  }else
  {
  cout << "Before copying the strings were not the same." << endl;
  if(strlen(first_str) < strlen(second_str))
    {
      cout << " pay attention bound" << endl;
    }
  strcpy(first_str, second_str);
  if (strcmp(first_str,second_str) == 0)
	 cout << "After copying the strings were the same. : " << first_str << endl;
}
  strcat(first_str, second_str);
	cout << "After concatenating, the first string is: " << first_str << endl;
  return 0;
}
void clear_bitmap(Logical map[][SCREEN_WIDTH],int screen_len)
{
  for(int h = 0; h < screen_len; h ++)
  {
    for(int w = 0; w < SCREEN_WIDTH; w++)
    {
      map[h][w] = False;
    }
  }
}
