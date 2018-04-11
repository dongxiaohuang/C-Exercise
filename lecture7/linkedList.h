#ifndef LINKED_LIST_H
#define LINKED_LIST_H
int const MAX_SIZE = 80;
struct Str_Node;
typedef Str_Node* NodePtr;
struct Str_Node
{
  char word[MAX_SIZE];
  NodePtr next;
};

void initialList(NodePtr &index_ptr);
void deleteNode(NodePtr first_ptr);
void printNode(NodePtr index_ptr);
#endif
