#ifndef SORTED_LIST
#define SORTED_LIST
#include "ExtendableArray.h"
template <typename T>
int defaultComp(const T& a, const T& b){
    return a < b ? -1: a == b ? 0:1;
}

template <typename T,
    // function template parameter
    int (*comp)(const T& a, const T& b) = defaultComp, //return type (*function name)(parameters)
    int MAXCAP = INT_MAX>
class SortedList {
private:
    /* data */
    const T _errVal;
    ExtendableArray<T> arr; // or use private inheritance as slides

    int locate(T val){
        int head = 0, tail = arr.count();
        int mid;
        if(comp(arr[head], val) > 0) return head;
        if(comp(val, arr[tail-1]) > 0) return tail;
        // if(arr[head] >= val) return head;
        // if(arr[tail-1] <= val) return tail;

        while(tail - head > 1){
            mid = (head + tail)/2;
            if(comp(arr[mid], val) > 0){
            // if(arr[mid] > val){
                tail = mid;
            }else if(comp(arr[mid], val) > 0){
            // }else if(arr[mid] < val){
                head = mid;
            }else return mid;
        }
        return mid;
    }
public:
    SortedList (int cap = 10, const T errVal = 0) : _errVal(errVal), arr(cap){}
    int count(){return arr.count();}
    T& get(int index){
        if( index >= 0 && index < arr.count())
            return arr[index];
        else return _errVal;
    }
    int indexOf(T val){
        int index = locate(val);
        if(comp(arr[index],val) == 0)
            return index;
        return -1;// cannot find
    }
    bool removeAt(int index){
        return arr.remove(index);
    }
    void add(T val){
        if(count() == 0) {
            arr.insert(val, 0);
            return;
        }
        int pos = locate(val);
        arr.insert(val, pos);
    }
    virtual ~SortedList (){};
    void print(){ cout << arr << endl;}
};

struct Point{
    int _x, _y;
    Point(int x=0, int y=0) : _x(x), _y(y){}
    static int comparePoint(const Point& p1, const Point& p2){
        if(p1._x == p2._x && p1._y == p2._y) return 0;
        int comp = (p1._x > p2._x) ? 1:0;
        if(!comp)
            comp = (p1._y > p2._y) ? 1:-1;
        return comp;
    }
};
ostream& operator<< (ostream&  o, const Point& p){
    return o << "["<< p._x << ", "<< p._y<<"]";
}
#endif
