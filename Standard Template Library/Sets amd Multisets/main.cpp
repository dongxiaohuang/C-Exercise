#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

/**
Set and multiset containers **sort**  their elements automatically according to a certain criterion
Set: unique sorted array
Multiset: sorted array allows duplicates

implemented as balanced binary tree
Problem: you may not change the value of element directly because it may compromise the correct order

#Operation:
- c.count(val): Returns the number of elements with value val
- c.find(val): Returns the position of the ﬁrst element with value val (or end() if none found)
- c.lower_bound(val): Returns the ﬁrst position, where val would get inserted (the ﬁrst element >= val)
- c.upper_bound(val): Returns the last position, where val would get inserted (the ﬁrst element > val)
- c.equal_range(val): Returns a range with all elements with a value equal to val (i.e., the ﬁrst and last position, where val would get inserted)
**/
int main(){
    // show how to use of lower_bound() upper_bound() and equal_range()
    set<int> c;
    c.insert(1);
    c.insert(2);
    c.insert(4);
    c.insert(5);
    c.insert(6);

    cout << "lower_bound(3): " << *c.lower_bound(3) << endl;
    cout << "upper_bound(3): " << *c.upper_bound(3) << endl;
    cout << "equal_range(3): " << *c.equal_range(3).first<< " "
                               << *c.equal_range(3).second<< endl;
    cout << endl <<  "====================" << endl;
    cout << "lower_bound(5): " << *c.lower_bound(5) << endl;
    cout << "upper_bound(5): " << *c.upper_bound(5) << endl;
    cout << "equal_range(5): " << *c.equal_range(5).first<< " "
                               << *c.equal_range(5).second<< endl;

    //insert return pair<iterator, bool>
    //descending order
    multiset<int, greater<int>> coll1;

    //insert elements in random order using different member functions
    coll1.insert({4,3,5,1,6,2});
    coll1.insert(5);

    //print all elements
    for(auto i : coll1)
        cout << i << ' ';
    cout << endl;


    //assign elements to another set with ascending order
    set<int> coll2(coll1.cbegin(), coll1.cend());
    //insert 4 again and process return value
    auto status = coll2.insert(4);
    if(status.second){
        cout << "4 inserted as element"
        << distance(coll1.begin(), status.first) +1 << endl;
    }else{
        cout << "4 already exists" << endl;
    }

    //print elements of coll2
    copy(coll2.cbegin(), coll2.cend(),
        ostream_iterator<int>(cout, " "));
    cout << endl;

    //remove all elements up to element with value 3
    coll2.erase(coll2.begin(), coll2.find(3));

    //remove all elements with value 5
    // coll2.remove(5); no remove function
    int count = coll2.erase(5);
    cout << "remove " << count << " element(s) removed" << endl;

    //print all elements
    for(auto i : coll2)
        cout << i << ' ';


    return 0;
}
