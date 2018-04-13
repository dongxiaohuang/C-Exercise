#include <array>
#include <iostream>

#include <algorithm>
#include <functional>
#include <numeric>
/*
   1. ordered collection
   2. suitable for a fixed number of elements
 */
using namespace std;

int main(){
        array<int, 4> x1; // the only container whose elements are initilized to 0 by default
        // for(auto i : x1){
        //     cout << i << endl;
        // }
        cout << x1[0] << endl;

        array<int, 5> coll1 = {{11, 12, 13, 14, 15}};
        array<int, 5> coll2 {{21, 22, 23, 24, 25}};
        array<int, 5> coll3;
        //only assign a list to an array during declaration

        coll3 = move(coll1); // container method move coll1 elements to coll3
        swap(coll1, coll2); // container method; swap
        for(auto i : coll1) {
                cout << i << " ";
        }
        cout << endl;
        for(auto i : coll2) {
                cout << i << ' ';
        }
        cout << endl;
        for(auto i : coll3) {
                cout << i << ' ';
        }
        cout << endl;
        // opration
        cout << "coll.empty() " << coll1.empty() << endl;
        cout << " coll.size() " << coll1.size() << endl;


/**** assignments ***/

        // int x[]= {1,3,4};
        // int y = x; // ERROR

        array<int,5 > coll4 = coll3;
        coll4.fill(7); // dill with element
        for(auto i : coll4) {
                cout << i << ' ';
        }
        cout << endl;
        /***Element access***/
        cout << "access using [idx] without range checking ";
        cout << coll1[5] << endl;
        cout << "access using at(idx) witht range checking ";
        // cout << coll1.at(5) << endl; // cause abort
        cout << endl;
/** using arrays as C-style array**/
        array<char, 41> a;
        char aa[41];
        strcpy(aa, "hello world");
        strcpy(&a[0], "hello world");
        cout<< &a[0]<< endl;
        cout << aa << endl;;
        // array name is not as address
        // but whenever c style is needed use array.data()
        strcpy(a.data(), "hello c++");
        cout << a.data() << endl;

/** examples of using Arrays**/

        //create array with 10 ints
        array<int, 10> example = {{11, 22, 33, 44}};
        cout << example.data()<< endl;
        for(auto i : example)
            cout << i ;
        cout << endl<<"====================" << endl;

        // modify last two elements
        example.back() = 9999;
        example[example.size()-2] = 8888;
        for(auto i : example)
            cout << i << ' ';
        cout << endl<< "====================" << endl;

        //process sum of all elements
        cout << "sum: "
            << accumulate(example.cbegin(), example.cend(), 0)
            << endl;
        //negate all elements
        transform(example.cbegin(), example.cend(), example.begin(), negate<int>());
        for(auto i : example)
            cout << i << ' ';
        cout << endl<<"====================" << endl;


}
