#ifndef EXTENDABLE_ARRAY_H
#define EXTENDABLE_ARRAY_H
#include <iostream>
using namespace std;
template <typename T, int MAXCAP = INT_MAX>
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
        _capacity = (capacity < MAXCAP) ? capacity : MAXCAP;
        _count = 0;
        _store = new T[_capacity];
    }
    bool ensureCapacity(int capacity){
        if(capacity > MAXCAP) return false;
        if(capacity > _capacity){
            while(_capacity < capacity) _capacity = _capacity*2 +1;
            if(_capacity > MAXCAP) _capacity = MAXCAP;
            resize(_capacity);
        }
        return true;
    }
    void compact(){
        resize(_count);
    }
    int count() const{
        return _count;
    }
    bool push_back(T val){
        return insert(val, _count);
    }
    bool remove(int index){
        if(index < 0 || index >= _count)
            return false;
        for(auto i = index; i < _count-1; i++){
            _store[i] = _store[i+1];
        }
        _count--;
        return true;
    }
    bool insert(T val, int index){
        if(index < 0) index = 0;
        int new_count = (index > _count ? index : _count) + 1;
        if(ensureCapacity(new_count)){
            for(auto i = new_count-1; i >= index+1; i--){
                _store[i] = _store[i-1];
            }
            _store[index] = val;
            _count = new_count;
            return true;
        }
        return false;
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
