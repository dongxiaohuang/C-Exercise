#include "ExtendableArray.h"
#include "SortedList.h"

int main(int argc, char const *argv[]) {
        ExtendableArray<double> arr(5);
        arr.push_back (1.1);
        arr.push_back (2.2);
        arr.push_back (3.3);
        arr.push_back (4.4);
        arr.push_back (5.5); // capacity arr.push_back (6.6); // internal
        for (float i = 10; i < 20; i++)
            arr.push_back(i);
        arr[2] = 30;

        arr.ensureCapacity(50); // extended to 95 arr.compact (); // internal store shrunk to 6
        arr.insert(777.2, 6);
        arr.remove(5);
        cout << arr << endl;
        cout << endl <<  "====================" << endl;

        SortedList<char> s1(10, '@');
        s1.add('c');
        s1.print();
        s1.add('e');
        s1.print();
        s1.add('a');
        s1.print();
        s1.add('b');
        s1.add('b');
        s1.add('b');
        s1.print();
        s1.add('a');
        s1.print();
        s1.add('g');
        s1.print();

        cout << s1.indexOf('b') << endl;
        cout << s1.indexOf('z') << endl;
        cout << s1.indexOf('a') << endl;

        cout << s1.removeAt(4) << endl;
        cout << s1.removeAt(3);
        s1.print();
        cout << s1.get(3) << endl;
        return 0;
}
