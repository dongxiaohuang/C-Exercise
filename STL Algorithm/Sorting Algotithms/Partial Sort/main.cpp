#include "helper.h"
#include <algorithm>
using namespace std;

/**
void partial_sort (RandomAccessIterator beg, RandomAccessIterator sortEnd,
                   RandomAccessIterator end) with operator <
                   []brg, end) [beg, sortEnd)

void partial_sort (RandomAccessIterator beg, RandomAccessIterator sortEnd,
                   RandomAccessIterator end, BinaryPredicate op)
**/

int main(){
    deque<int> coll;

    INSERT_ELEMENTS(coll, 3, 7);
    INSERT_ELEMENTS(coll, 2, 6);
    INSERT_ELEMENTS(coll, 1, 5);
    PRINT_ELEMENTS(coll);

    //sort until the first five elements are sort
    partial_sort(coll.begin(),
                coll.begin()+5,
                coll.end());
    PRINT_ELEMENTS(coll);

    //sort inversely until the first five elements are sorted
    partial_sort(coll.begin(), coll.begin()+5, coll.end(), greater<int>());
    PRINT_ELEMENTS(coll);

    //sort all elements
    partial_sort(coll.begin(), coll.end(), coll.end());

    PRINT_ELEMENTS(coll);

    cout << endl <<  "====================" << endl;

/**
RandomAccessIterator partial_sort_copy (InputIterator sourceBeg, InputIterator sourceEnd, RandomAccessIterator destBeg, RandomAccessIterator destEnd)

RandomAccessIterator partial_sort_copy (InputIterator sourceBeg, InputIterator sourceEnd,

RandomAccessIterator destBeg, RandomAccessIterator destEnd, BinaryPredicate op)
**/

    deque<int> coll1;
    vector<int> coll6(6);
    vector<int> coll30(30);

    INSERT_ELEMENTS(coll1, 3, 7);
    INSERT_ELEMENTS(coll1, 2, 6);
    INSERT_ELEMENTS(coll1, 1, 5);
    PRINT_ELEMENTS(coll1);

    //copy elements of coll1 sorted into coll6

    partial_sort_copy(coll1.cbegin(), coll1.cend(),
                     coll6.begin(), coll6.end());

    PRINT_ELEMENTS(coll6);

    //copy elements of coll1 inversely sorted into coll30

    partial_sort_copy(coll1.cbegin(), coll1.cend(),
                     coll30.begin(), coll30.end(),
                    greater<int>());

    PRINT_ELEMENTS(coll30);



}
