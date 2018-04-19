#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

//A deque(pronounced "deck") is very similar to vector. It manages its elements with a dynamic array, provide random
// access and has almost the same interface as a vector
// difference between vector and deque is that:
// with a deque, dynamic array is open at both ends.
// Thus, a deque is fast for insertions and deletions at both the end and the beginning ( for vector it is only fast to do in the end)

/**
            ___________
        <-    | | | |   ->
            -----------
        push_front()    pop_front()
        push_end()      pop_end()
# in summary you should prefer to use deque in the following situations:
 - You insert and remove elements at both ends( typical for a queue)
 - You dont refer to elements of the container
 - It is important that the container frees memory when it is no longer used(howerer, the standard does not guarantee this happens)

**/



int main(){

    //create empty deque of strings
    deque<string> coll;

    //insert several elements
    coll.assign(3, string("string")); // Assigns n copies of elements elem
    coll.push_back("last string");
    coll.push_front("first string");

    //print elements separated by newline
    for(auto i : coll)
        cout << i << endl;
    // copy(coll.begin(), coll.end(),
    //     ostream_iterator<string>(cout, "\n"));
    // cout << endl;

    //remove first and last elements
    coll.pop_back();
    coll.pop_front();

    cout << endl <<  "====================" << endl;
    //insert "another" into every element but the first
    for(auto i = 1; i < coll.size(); ++i)
        coll[i] = "another " + coll[i];

    //change size to four elements if size grows new elements are copies of elem
    coll.resize(4, "new string");

    //print out
    for( auto i : coll)
        cout << i << endl;
    return 0;
}
