#include <iostream>
#include <cctype>
#include <cmath>
#include <iomanip>

using namespace std;
enum {MON, TUES, WED, THURS, FRI, SAT, SUN};

int main()
{
  char a;


for(a = 'A'; a <= 'z'; a++ )
{
  cout.setf(ios::fixed);
  cout.precision(2);
  if(! isalpha(a))
  {
  }
  else
  {
    cout <<a << " it is " << static_cast<float>(a) << " in ASCII" << endl;
    if(islower(a))
    {
      cout << "its upppercase is "<< (char)toupper(a) << endl;
    }
    else
    {
      cout << "its lower case is "<< (char)tolower(a) << endl;
    }
  }
}
// tab the sqrt
  cout << setiosflags(ios::left);
  cout.width(20);
  cout << "Number" << "Sqrt of number" << endl;

  for(int i = 1; i <= 10; i++)
    {
      cout.width(20);
      cout.setf(ios::fixed);
      cout.precision(2);
      cout << i << sqrt(i) << endl;
    }
// enum
cout << MON << endl;
  return 0;
}
