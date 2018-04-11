#include <iostream>
using namespace std;

int main()
{
  int current_year, current_age, some_year, age_some_year;
  cout << "Enter your current year then press RETURN" << endl;
  cin >> current_year;
  cout << "Enter your current age in years." << endl;
  cin >> current_age;
  cout << "Enter the year for which you wish to know your age."<< endl;
  cin >> some_year;
  age_some_year = some_year - current_year + current_age;
  if(age_some_year >= 0)
  {
    cout << "Your age in "<< some_year<<": "<< age_some_year << endl;
  }else
  {
    cout << "You weren't even born in ";
			cout << some_year << "!\n";
  }
  return 0;
}
