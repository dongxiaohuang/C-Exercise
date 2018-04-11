#include "self_up_dow.h"

ostream& operator<<(ostream& out, const Up u)
{
  out << "index is now : "<<u.index << endl;
  return out;
}

Up Up::operator++()
{
  ++index;
  return *this;
}

Up Up::operator++(int dummy) // posterior add a dummy int
{
  index++;
  return *this;
}
