#include "linkedList.h"
#include <iostream>
#include <cstring>
using namespace std;

void initialList(NodePtr &first_ptr)
{
  NodePtr index_ptr, last_ptr;
  cout << "Please input a word ,(or '.' to end list): " << endl;
  first_ptr = new Str_Node;
  cin >> first_ptr -> word;
  if(strcmp(first_ptr -> word, ".") == 0)
  {
    delete first_ptr;
    first_ptr = NULL;
  }
  index_ptr = first_ptr;
  while(index_ptr != NULL)
  {
    cout << "Enter next word (or '.' to end list): ";
    last_ptr = new Str_Node;
    cin >> last_ptr -> word;
    if(strcmp(last_ptr -> word, ".") == 0)
    {
      delete last_ptr;
      last_ptr = NULL;
    }
    index_ptr -> next = last_ptr;
    index_ptr = last_ptr;
  }

}

void deleteNode(NodePtr first_ptr)
{
  NodePtr index_ptr;
  index_ptr = first_ptr;
  while(index_ptr != NULL)
  {
    first_ptr = first_ptr -> next;
    delete index_ptr;
    index_ptr = first_ptr;
  }
}
void printNode(NodePtr index_ptr)
{
  while (index_ptr != NULL) {
    cout << index_ptr -> word << " ";
    index_ptr = index_ptr -> next;
  }
  cout << endl;
}
