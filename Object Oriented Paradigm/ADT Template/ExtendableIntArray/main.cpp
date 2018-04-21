#include "ExtendableIntArray.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    ExtendableIntArray arr(5);
    arr.push_back(10);
    arr.push_back(11);
    arr.push_back(12);
    arr.push_back(13);
    arr.push_back(14);
    arr.push_back(15);
    arr[2] = 7;
    cout << arr.capacity() << endl;
    cout << arr.count() << endl;
    arr.ensureCapacity(50);
    cout << arr.capacity() << endl;
    cout << arr.count() << endl;
    arr.shrink_to_fit();
    cout << arr.capacity() << endl;
    cout << arr.count() << endl;
    // cout << arr;
    cout << arr <<endl;
    return 0;
}
