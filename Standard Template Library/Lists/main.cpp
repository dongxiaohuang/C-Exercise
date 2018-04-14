#include "helper.h"
#include <iostream>
#include <algorithm>


int main(){
    // a list does not provide random access
    // isnert or delete element cost const time

    // create two empyty lists
    list<int> list1, list2;

    //fill both lists with elements
    for(int i=0; i<6; ++i){
        list1.push_back(i);
        list2.push_back(i);
    }
    list1.push_front(11);
    list2.push_front(22);
    printLists(list1, list2);

    //insert all elements of list1 before the first element with
    // value 3 of list2

    //-find() returns an iterator to the first element with value 3
    // move all the element of list1 to list2 in ront of iterator position
    list2.splice(find(list2.begin(), list2.end(),3), // destination position
                list1); // source list
    printLists(list1, list2);

    // move first element of list2 to the end
    list2.splice(list2.end(),//destination position
                 list2,//source
                 list2.begin()//source position
             );
    printLists(list1, list2);

    //sort second list assign to list1 and remove duplicates
    list2.sort();
    list1 = list2;
    list2.unique();
    printLists(list1, list2);

    //merge both sorted lists into the first list
    list1.merge(list2);
    printLists(list1, list2);

    //erase by position
    list2 = list1;
    list2.erase(list2.begin()); // list2.front() is a value not position

    //remove by value
    list2.remove(1);
    list2.remove_if([] (int i){
        return i%2 != 0;
    });
    printLists(list1, list2);
    return 0;
}
