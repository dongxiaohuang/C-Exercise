#ifndef EXTENDABLE_INT_ARRAY_H
#define EXTENDABLE_INT_ARRAY_H
#include <iostream>
using namespace std;
class ExtendableIntArray {
private:
    /* data */
    int _count;
    int _capacity;
    int* _store;
    void resize(int size);//helper function
public:
    int& operator[](int index);
    ExtendableIntArray (int _capacity = 10);
    void ensureCapacity(int capacity);
    void compact();
    int count() const;
    void push_back(int val);
    int capacity() const;
    void shrink_to_fit();
    virtual ~ExtendableIntArray ();
    friend ostream& operator<< (ostream&, ExtendableIntArray& ea);;
    //seems that can only be friend
};
#endif
