#ifndef SORTED_LIST
#define SORTED_LIST
#include "ExtendableArray.h"

template <typename T, int MAXCAP = INT_MAX>
class SortedList {
private:
    /* data */
    const T _errVal;
    ExtendableArray<T> arr; // or use private inheritance as slides

    int locate(T val){
        int head = 0, tail = arr.count();
        int mid;
        if(arr[head] >= val) return head;
        if(arr[tail-1] <= val) return tail;

        while(tail - head > 1){
            mid = (head + tail)/2;
            if(arr[mid] > val){
                tail = mid;
            }else if(arr[mid] < val){
                head = mid;
            }else return mid;
        }
        return mid;
    }
public:
    SortedList (int cap = 10, const T errVal = 0) : _errVal(errVal), arr(cap){}
    int count(){return arr.count();}
    T get(int index){
        if( index >= 0 && index < arr.count())
            return arr[index];
        else return _errVal;
    }
    int indexOf(T val){
        int index = locate(val);
        if(arr[index] == val)
            return index;
        return -1;// cannot find
    }
    bool removeAt(int index){
        return arr.remove(index);
    }
    void add(T val){
        int pos = locate(val);
        arr.insert(val, pos);
    }
    virtual ~SortedList (){};
    void print(){ cout << arr << endl;}
};
#endif
