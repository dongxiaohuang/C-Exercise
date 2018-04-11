#include "info.h"
#include <iostream>
using namespace std;

void Info::Init(){
  cout << "common initial statements "<< endl ;
}

Info::Info()
{
  Init();

}

Info::Info(int i):Info()
{
  id = i;
}

Info::Info(char c) : gender(c){Info();}

Info::~Info()
{
  cout <<this->id << " bye" << endl;
}

void Info::print()
{
  cout << "this is the Info of id = " << id<<endl;
}

// Info::Info(const Info &src)
// {
//   cout << "copy function";
// }
// if we override the copy function it will show differently


void Info::func1(Info i)
{
  cout << "funct1" << endl;
}

Info Info::func2()
{
  cout << "funct2" << endl;
  return Info();
}
auto func3() -> int
{
  cout << " func3 -> int" <<endl;
  return 0;
}

void change_i_val(int another_i, Info &info) // if we donnt use & we will use copy constructor
{
  info.id = another_i;
  // private member and use obj.private member
}
