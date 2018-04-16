#include "helper.h"
#include <iostream>

using namespace std;

/**
heap:
1. the first element is one of the largest
2. you can add or remove an element in logarithmic time

used as priority_queue container
The STL provides four algorithms to handle a heap:

1. make_heap() converts a range of elements into a heap.

2. push_heap() adds one element to the heap.

3. pop_heap() removes the next element from the heap.

4. sort_heap() converts the heap into a sorted collection, after which it is no longer a heap.

In addition, since C++11, is_heap() and is_heap_until() are provided to check whether a collection is a heap
or to return the ﬁrst element that breaks the property of a collection to be a heap
**/
int main(){
    vector<int> coll;

    INSERT_ELEMENTS(coll,3,7);
    INSERT_ELEMENTS(coll,5,9);
    INSERT_ELEMENTS(coll,1,4);

    PRINT_ELEMENTS(coll, "on entry:     ");

    //convert collection into a heap
    make_heap(coll.begin(), coll.end());
    PRINT_ELEMENTS(coll, "after make_heap()  ");

    //pop next elment out of heap
    pop_heap(coll.begin(), coll.end());
    coll.pop_back();

    PRINT_ELEMENTS(coll, "after pop_heap()  ");

    coll.push_back(17);
    push_heap(coll.begin(), coll.end());
    PRINT_ELEMENTS(coll, "after push_heap()  ");

    // convert heap into a sorted collection
    //NOTE after call it is no longer a heap

    sort_heap(coll.begin(), coll.end());

    PRINT_ELEMENTS(coll);
//9 |8 6 |7 7 5 5| 3 6 4 1 2 3 4
    return 0;
}
