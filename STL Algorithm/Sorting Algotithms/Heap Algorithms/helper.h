// algo/algostuff.hpp

#ifndef ALGOSTUFF_H
#define ALGOSTUFF_H

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include <iostream>
#include <string>

// INSERT_ELEMENTS (collection, first, last) // - ﬁll values from ﬁrst to last into the collection
// - NOTE: NO half-open range
template <typename T>
inline void INSERT_ELEMENTS (T& coll, int first, int last) {

for (int i=first; i<=last; ++i) {

coll.insert(coll.end(),i);

} }

// PRINT_ELEMENTS()
// - prints optional string optcstr followed by
// - all elements of the collection coll
// - separated by spaces
template <typename T>

// Chapter 11: STL Algorithms

inline void PRINT_ELEMENTS (const T& coll, const std::string& optcstr="")
{ std::cout << optcstr;
    for (auto elem : coll)
     { std::cout << elem << ' ';}
     std::cout << std::endl; }

// PRINT_MAPPED_ELEMENTS()
// - prints optional string optcstr followed by
// - all elements of the key/value collection coll
// - separated by spaces
template <typename T>
inline void PRINT_MAPPED_ELEMENTS (const T& coll, const std::string& optcstr="") {

    std::cout << optcstr;

    for (auto elem : coll) {

        std::cout <<" [ "<< elem.first << ", "<< elem.second << "] ";

    };

    std::cout << std::endl; }

bool lessLength(const std::string& s1, const std::string& s2){
    return s1.length() < s2.length();
}
#endif /*ALGOSTUFF_HPP*/
