#include "helper.h"

int Helper::number = 0;

Helper::Helper(int id):ID(id)
{
  number++;
}
Helper::~Helper()
{
  number--;
}
// static int Helper::getNum()
// {
//
// }
int Helper::getID() const
{
  return ID;
}
int Helper::showId()
{
  return ID;
}
