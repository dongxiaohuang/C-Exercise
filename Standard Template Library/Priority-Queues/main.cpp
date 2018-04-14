#include <queue>
#include <iostream>

using namespace std;

int main(){
    // container adapter
    // by default using operator < in descend order
    //              --------- top()-
    // -->push()   |                |-> pop()
    //              ----------------
    priority_queue<float> q;

    // insert three elements into the priority queue
    q.push(66.6);
    q.push(22.2);
    q.push(44.4);

    //read and print two elements
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    q.pop();

    // insert three more elements
    q.push(11.1);
    q.push(55.5);
    q.push(33.3);

    //skip one element
    q.pop();

    //pop and print remaining elements
    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl <<  "====================" << endl;
    priority_queue< int, vector<int>, greater<int> > q2;
    // type sequence container(provide ramdom access) sort criterion
    q2.push(5);
    q2.push(9);
    q2.push(1);
    while(!q2.empty()){
        cout << q2.top()<< ' ';
        q2.pop();
    }
    cout << endl;
}
