#include <iostream>
#include "test.h"
#include "week.h"
#include "self_up_dow.h"
using namespace std;

int main()
{
  Test t(3);
  Test t_new(1);
  t = t;
  t_new = t;
  cout << "please input id of the t" << endl;
  cin >> t;
  cout << "override << \n" <<t << endl;
  Test sum(1);
  int s= sum(1,3); // class function
  cout <<"s is of value of " << s << endl;
  /**
 * Test for change the square braket
 */
 WeekTemp beijing;
 beijing["Mon"] = 5;
 cout << beijing["Mon"] << endl;
 /**
 * test for self up and down
 */

 Up u(4);
 cout << u;
 u++;
 cout << u;
 ++u;
 cout << u;

}
