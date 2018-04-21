#include "ExtendableArray.h"

int main(int argc, char const *argv[]) {
        ExtendableArray<double> arr(5);
        arr.push_back (1.1);
        arr.push_back (2.2);
        arr.push_back (3.3);
        arr.push_back (4.4);
        arr.push_back (5.5); // capacity arr.push_back (6.6); // internal

        arr [2] = 30;

        arr.ensureCapacity(50); // extended to 95 arr.compact (); // internal store shrunk to 6
        cout << arr;
        return 0;
}
