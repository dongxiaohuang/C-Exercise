#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include "testPointer.h"
#include "linkedList.h"

using namespace std;

typedef int* IntPtr;
int const MAX_LEN = 80;
int main()
{
  int a = 3;
  IntPtr i = &a;
  cout << "address of i " <<i << endl;
  cout << "value of i "<< *i << endl;
  int *ptr;
  ptr = new (nothrow) int;
  if(ptr == NULL)
  {
    cout << "sorry run out of memory" << endl;
    exit(1);
  }
  delete ptr;
// array and pointer

  int hours[6] = {1,2,3,4,5,6};
  ptr = hours;//address
  for (int i = 0; i < 6; i++) {
    cout << setiosflags(ios::left);
    cout.width(20);
    cout << *(ptr +i);
    if((i+1)%2 == 0)
    cout << endl;
  }
// -- to upper case
  char * str_ptr ;
  char str[30];
  strcpy(str, "this is a sentence.");
  str_ptr = str;
  int index = 0;
  while(str[index] != '\0')
  {
    str[index] = (char) toupper(str[index]);
    index++;
  }

    cout << str_ptr << endl;

  while(*str_ptr != '\0')
  {
    *str_ptr = static_cast<char>(tolower(*str_ptr));
    str_ptr++; // point to the most left
  }

  cout << str << endl;
  // --------dynamic allocate
  cout << "-----------------------" << endl;
  int len;
  int * int_ptr;
  int sum = 0;
  cout << "Please input the length of numbers" << endl;
  cin >> len;
  int_ptr = new int[len];
  for(int i = 0; i < len; i++)
  {
    cout << "please input the value for value"<<i+1<<" : ";
    cin >> int_ptr[i];
    sum += int_ptr[i];
  }
  cout.setf(ios::fixed);
  cout.precision(2);
  cout << "the average of the list of number is : " <<(float)sum/len << endl;
  delete [] int_ptr;

  // --------linked list
struct Node
{
  char word[MAX_LEN];
  Node * next;
};
  Node my_node, next_node;
  strcpy(my_node.word, "first word");
  strcpy(next_node.word, "next word");
  next_node.next = NULL;
  my_node.next = & next_node;
  Node* loopNode;
  loopNode = &my_node;
  while(loopNode != NULL)
  {
    cout << loopNode->word << endl;
    loopNode = loopNode -> next ;
  }


  //------test testPointer
  char list[3] = {'1','2','3'};
  char *ptr_list = list;
  cout <<"-----testing---"<< endl;
  cout << ptr_list << endl;
  // test1(ptr_list);
  // cout << "after test1 : " << ptr_list << endl;
  test2(ptr_list);
  cout << "after test2 : " << ptr_list << endl;
  // cout << ptr_list << endl;
  // test3(list);
  // cout << "after test3 : " << list << endl;
  NodePtr first_ptr = NULL;
  initialList(first_ptr);// this must be a reference because it is initilized in the function and it previous point to NULL
  printNode(first_ptr);
  deleteNode(first_ptr);

  return 0;
}
