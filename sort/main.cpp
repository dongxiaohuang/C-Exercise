#include "helper.h"
#include "bubblesort.h"
#include "simple_selection.h"
#include "straight_insertion.h"
#include "shell_sort.h"
#include "heap_sort.h"
#include "merging_sort.h"
#include "quick_sort.h"
#include <iostream>

using namespace std;

int main()
{
  int list[10] = {3,2,1,0,4,9,10,33,37,40};
  bubblesort1(list, 10);
  for (int i = 0; i < 10; i++) {
    cout << list[i] << " " ; }
  cout << endl;

  int list1[10] = {3,2,1,0,4,9,10,33,37,40};
  bubblesort_impr(list1, 10);
  for (int i = 0; i < 10; i++) {
    cout << list1[i] << " " ; }
  cout << endl;

  int list2[10] = {3,2,1,0,4,9,10,33,37,40};
  simple_selection_sort(list2, 10);

  for (int i = 0; i < 10; i++) {
    cout << list2[i] << " " ; }
  cout << endl;

  int list3[10] = {3,2,1,0,4,9,10,33,37,40};
  straight_insertion_sort(list3, 10);

  for (int i : list3) {
    cout << i << " " ; }
  cout << endl;

  int list4[10] = {3,2,1,0,4,9,10,33,37,40};
  shell_sort(list4, 10);

  for (auto e : list4) {
    cout << e << " " ; }
  cout << endl;

  int list5[10] = {3,2,1,0,4,9,10,33,37,40};
  heap_sort(list5, 10);

  for(auto e : list5)
    cout << e << " ";
  cout << endl;

  int list6[10] = {3,2,1,0,4,9,10,33,37,40};
  quick_sort(list6, 0, 9);

  for(auto e : list6)
    cout << e << " ";
  cout << endl;


  int list7[10] = {3,2,1,0,4,9,10,33,37,40};
  merging_sort(list7, 0, 9);

  for(auto e : list7)
    cout << e << " ";
  cout << endl;

  return 0;
}
