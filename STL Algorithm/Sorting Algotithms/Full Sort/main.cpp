#include "helper.h"
#include <algorithm>
using namespace std;



int main(){
    // sort using quicksort
    //stable_sort: using merge sort
    // difference is stable_sort guarantees the order of equal elements remains stable
    // stable_sort : keep original sequency when a tie is reached by a criterion
    //interator used must be RandomAccessIterator so the list accociative and unirdered containers are not be able to used
    // Howerver, they provide special member function to sort elements

    deque<int> coll;
    INSERT_ELEMENTS(coll, 1, 9);
    INSERT_ELEMENTS(coll, 1, 9);

    PRINT_ELEMENTS(coll, "on entry: ");

    // sort elements
    sort(coll.begin(), coll.end());// default op = '<'
    PRINT_ELEMENTS(coll, "Sorted:  ");

    //sorted reverses
    sort(coll.begin(), coll.end(), greater<int>());

    PRINT_ELEMENTS(coll, "sorted > : ");

    cout << endl <<  "====================" << endl;
    /* difference between sort and stable sort*/
    vector<string> coll1 = { "1xxx", "2x", "3x", "4x", "5xx", "6xxxx", "7xx", "8xxx", "9xx", "10xxx", "11", "12", "13", "14xx", "19", "16", "17" };

    vector<string> coll2(coll1);

    PRINT_ELEMENTS(coll1, "on entry:\n ");

    //sort(according to the length of strings)
    sort(coll1.begin(), coll1.end(),//range
            lessLength// criterion
        );

    stable_sort(coll2.begin(), coll2.end(),
            lessLength// criterion
        );

    PRINT_ELEMENTS(coll1, "\n with sort(): \n");
    PRINT_ELEMENTS(coll2, "\n with stable_sort(): \n");
    return 0;
}
