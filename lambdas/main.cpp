#include <iostream>
#include <string>
using namespace std;

int main(){
    //minimal lambda function
    auto l = []{
        cout << "hello lambda"<< endl;
    };

    l(); // call by object

    //directly call lambda
    []{
        cout << "hello lambda"<< endl;
    }();

    // lambda with parameters
    auto l2 = [] (const string& s){
        cout << s << endl;
    };
    l2("hello lamba");

    [] (const string& s){
       cout << s << endl;
    }("hello lamba");

    //lambda with return
    []{
        return 42; // deduct from return type in this case int
    }();
    // specify return type
    [] () -> double{
        return 42;
    }();

    // captures (access to Outer Scope)
    // - [=]: means the outer scope is passed to lambda by value
    // thus you can read but not modify all data
    // - [&]: means the outer scope is passed to lambda by reference
    // thus you can write and read all data

    int x = 0;
    int y = 42;
    auto qqq = [x, &y]{// x pass by value so copy x = 0
    // auto qqq = [=, &y]{// x pass by value so copy x = 0
    // the same as above, all pass by value except from y (by reference)
        cout << "x " << x << endl;
        cout << "y " << y << endl;
        ++y;
    };
    x = y = 77;
    qqq();
    qqq();
    cout << "final y " << y << endl;
    cout << "final x " << x << endl;
}
