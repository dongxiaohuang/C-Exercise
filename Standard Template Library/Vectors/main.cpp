#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// an vector is a dynamic array
int main(){
/** capacity of vector **/
    vector<int> v1;
    cout << "v1 initial with size = such as " << v1.capacity() << endl;// may waste of memory or cause reallocation
    v1.reserve(80);
    vector<int> v2(80); // reserve80 elments for vector
    // this is because rellocation is expensive
    //capacity of vector never shrink
    //c++11 introduce a way to shrink by calling `shrink_to_fit()`
    v2.shrink_to_fit();
    cout << v2.capacity()<< endl;
    cout << endl <<  "====================" << endl;
/** vector operation **/

    v2 = {1,2,3,4,11,22,33,44};
    cout << "c[idx] " << v2[0]<< endl; // no range check
    cout << "c.at() " << v2.at(0)<< endl; // range check
    cout << "c.front() " << v2.front()<< endl;// no range check
    cout << "c.end() " << v2.back()<< endl;// no range check
    if(!v2.empty())
        cout << v2.front() << endl;
    if(v2.size() > 5)
        cout << v2[5] << endl;
    //inserting and removing elements of vector
    v2.push_back(99);
    cout << "after inserting : "<< v2.back() << endl;
    v2.pop_back();
    cout << "after removing : "<< v2.back() << endl;

    v2.insert(v2.begin()+2, 77); // pos is an iterator position
    v2.insert(v2.begin()+7, 77); // pos is an iterator position
    cout << v2.at(7) << endl;

    // v2.erase(remove(v2.cbegin(), v2.cend(), 77), v2.end());
    remove(v2.begin(), v2.end(), 77); // remove all the elements with value 77
    for(auto i : v2)
        cout << i << ' ';
    cout << endl;

    // remove sertain first element with value 33
    auto pos = find(v2.cbegin(), v2.cend(), 33);
    v2.erase(pos);
    for(auto i : v2)
        cout << i << ' ';
    cout << endl;

/** Using vector as C-style arrays **/

    //continuous memory
    vector<char> str_vec(40);
    strcpy(&str_vec[0], "hello world");
    cout << &str_vec[0] << endl;
    strcpy(str_vec.data(), "hello c++");
    cout << str_vec.data() << endl;

cout << endl <<  "==========Examples==========" << endl;
/** Examples of Using Vectors **/
    //create empty vector for strings
    vector<string> sentence;

    //reserve memory for five elemnts to avoid reallocation
    sentence.reserve(5);

    //append some elements
    sentence.push_back("Hello,");
    sentence.insert(sentence.end(), {"how", "are", "you", "?"});

    //print elements separated with spaces
    for(auto i : sentence){
        cout << i << " ";
    }
    cout << endl;

    //print technical data
    cout << " max_size() " << sentence.max_size()<< endl;
    cout << " size() " << sentence.size() << endl;
    cout << " capacity() " << sentence.capacity() << endl;

    //swap second and fourth element
    swap(sentence[1], sentence[3]);

    //insert elemnt "always" before element "?";
    sentence.insert(find(sentence.cbegin(), sentence.cend(), "?"),
    "always");

    //delete first element "how"
    sentence.erase(find(sentence.cbegin(), sentence.cend(), "how"));

    // assign the last element to "handsome"
    sentence.back() = "handsome";

    //print technical data again
    cout << " max_size() " << sentence.max_size()<< endl;
    cout << " size() " << sentence.size() << endl;
    cout << " capacity() " << sentence.capacity() << endl;

    //push elements
    sentence.push_back("!");
    sentence.push_back("!");

    //pop element
    sentence.pop_back();

    //shrink capacity
    sentence.shrink_to_fit();

    for(auto i : sentence){
        cout << i << " ";
    }
    cout << endl;
    //print technical data again
    cout << " max_size() " << sentence.max_size()<< endl;
    cout << " size() " << sentence.size() << endl;
    cout << " capacity() " << sentence.capacity() << endl;
}
