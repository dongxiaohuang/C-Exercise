#include "test.h"

Test::Test(int i):id(i){cout << "obj "<< id << " is created \n";}

Test& Test::operator=(const Test& t)
{
  if(this == &t)
  {
    cout << "same obj!\n";
  }else
  {
    cout << "this -> id" << this -> id <<" change to t.id" << t.id<<endl;
    this -> id = t.id;
  }
  return *this;
}


ostream& operator<<(ostream& out, const Test& t)
{
  out << "the obj is of id = "<< t.id<<endl;
  return out;
}

istream& operator>>(istream& in, Test& t)
{
  in >> t.id; // in this case this is able because id is int if this
  // is another selfdefined type, we need to enable >> that class or it
  //will not be able to compile
  return in; // need to return in; because we need to enable >> >> link input
}

int Test::operator()(int a, int b)
{
  cout << "operator() is called \n";
  return a+b;
}
