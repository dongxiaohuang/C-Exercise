#include "ExtendableIntArray.h"
ExtendableIntArray::ExtendableIntArray(int capacity){
    _capacity = (capacity > 0) ? capacity : 0;
    _count = 0;
    _store = new int[_capacity];
}
int& ExtendableIntArray::operator[](int index){
    return _store[index];
}

int ExtendableIntArray::capacity() const {return _capacity;}
int ExtendableIntArray::count() const {return _count;}
void ExtendableIntArray::shrink_to_fit(){
    resize(_count);
    _capacity = _count;
}
void ExtendableIntArray::resize(int size){
    int* newstore = new int[size];
    for(auto i = 0; i < size; i++)
        newstore[i] = _store[i];
    delete [] _store;
    _store = newstore;
}
void ExtendableIntArray::ensureCapacity(int capacity){
    if(capacity > _capacity){
        while(_capacity < capacity) _capacity = _capacity*2 +1;
        resize(_capacity);
    }
}
void ExtendableIntArray::push_back(int val){\
    if(_count >= _capacity){
        ensureCapacity(_count+1);
    }
    _store[_count++] = val;
    // _store[_count] = val;
    // _count++;
}
ostream& operator<< (ostream& o, ExtendableIntArray& ea){
    o << '[';
    for(auto i = 0; i < ea.count() -1; i++)
        o << ea[i] << ",";
    o << ea[ea.count()-1]<<']';
    return o;
}
ExtendableIntArray::~ExtendableIntArray(){delete[] _store;}
