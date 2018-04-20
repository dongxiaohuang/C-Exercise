#include <iostream>
#include <memory> //smart pointer
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    //two shared pointers representing two persons by their names
    shared_ptr<string> pJutta(new string("jutta"));
    shared_ptr<string> pNico(new string("nico"),
        // self-defined deleter
        //default is delete single object you need to specify if it points to an array
        [](string* p){
            cout << "deleting p" << endl;
            delete p;
        }
    );
    // shared_ptr<string> pNico{new string("nico"))}; // OK!
    // shared_ptr<string> pNico = make_shared<string>("nico"); // use function
    // shared_ptr<string> pNico2 = new string("nico"); //illegal

    //capitalize person names
    (*pNico)[0] = 'N';
    pJutta->replace(0,1,"J");

    pJutta.reset(new string("Juttalia")); // reset you cannot use assignment

    //put them multiple times in a container
    vector<shared_ptr<string>> whoMadeCoffee; // usually create its own copy of elements passed in
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);

    //print all elements
    for(auto ptr : whoMadeCoffee){
        cout << *ptr << " ";
    }
    cout << endl;

    //overwrite name again
    *pNico = "Nicolas";
    for(auto ptr : whoMadeCoffee)
        cout << *ptr << " ";
    cout << endl;

    // print some internal data
    cout << "use_count(): ie. it has  " << whoMadeCoffee[0].use_count() << " pointers pointing to " << *whoMadeCoffee[0]<<endl;

    return 0;
}
