#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char** argv)
{
  int a, b;
  if(argc != 3)
  {
    cout << "please input 2 integers"<<endl;
    return 1;
  }
  a = atoi(argv[1]);
  b = atoi(argv[2]);
  cout << "the number of argc " << argc << endl;
  cout << "the sum of a + b " <<a+b<< endl;
  return 0;
 }
