#ifndef EXTENDABLE_ARRAY_H
#define EXTENDABLE_ARRAY_H
#include <iostream>
using namespace std;
template <typename T>
//as a template, implement written in header file
class ExtendableArray {
private:
    /* data */
    int _count;
    int _capacity;
    T* _store;
    void resize(int size){
        T* newstore = new T[size];
        for(auto i = 0; i < size; i++)
            newstore[i] = _store[i];
        delete [] _store;
        _store = newstore;
    }//helper function
public:
    T& operator[](int index){
        return _store[index];
    }
    ExtendableArray (int capacity = 10){
        _capacity = (capacity > 0) ? capacity : 0;
        _count = 0;
        _store = new T[_capacity];
    }
    void ensureCapacity(int capacity){
        if(capacity > _capacity){
            while(_capacity < capacity) _capacity = _capacity*2 +1;
            resize(_capacity);
        }
    }
    void compact();
    int count() const{
        return _count;
    }
    void push_back(T val){
        if(_count >= _capacity){
            ensureCapacity(_count+1);
        }
        _store[_count++] = val;
        // _store[_count] = val;
        // _count++;
    }
    int capacity() const{return _capacity;}
    void shrink_to_fit(){
        resize(_count);
        _capacity = _count;
    }
    virtual ~ExtendableArray (){delete[] _store;}
    friend ostream& operator<< (ostream& o, ExtendableArray<T>& ea){
        o << '[';
        for(auto i = 0; i < ea.count() -1; i++)
            o << ea[i] << ", ";
        o << ea[ea.count()-1]<<']';
        return o;
    }
    //seems that can only be friend
};
#endif
