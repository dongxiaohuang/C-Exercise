#include <iostream>
#include "binary_search.h"
#include "sequential_search.h"
#include "interpolation_search.h"
using namespace std;

int main()
{
  int list[5] = {1,2,3,4,7};
  int result = binary_search(list, 0,4,7);
  if(result == -1)
    cout << "cannot find" << endl;
  else cout << "BINARY SEARCH: found in the index of " << result << endl;
  result = sequential_search(list, 5, 0);
  if(result == -1)
    cout << "cannot find" << endl;
  else cout << "SEQUENTIAL SEARCH : found in the index of " << result << endl;
  result = interpolation_search(list, 0, 4,7);
  if(result == -1)
    cout << "cannot find" << endl;
  else cout << "INTERPOLATION SEARCH : found in the index of " << result << endl;
  return 0;
}
