#include <set>
#include <algorithm>
#include "helper.h"
using namespace std;

//type for runtime sorting criterion
class RuntimeCmp {
public:
    enum cmp_mode {normal, reverse};
private:
    cmp_mode mode;
public:
    //constructor for soring criterion
    //- default criterion uses value normal
    RuntimeCmp(cmp_mode m=normal) : mode(m){
    }

    //comparison of elements
    //- member function for any element type
    template <typename T>
    bool operator()(const T& t1, const T& t2) const{
        return mode==normal ? t1<t2
                            : t2<t1;
    }
    //comparison of sorting criteria
    bool operator== (const RuntimeCmp& rc) const{
        return mode == rc.mode;
    }
};

//type of a set that uses this sorting criterion
typedef set<int, RuntimeCmp> IntSet;

int main(int argc, char const *argv[]) {
    /* code */
    //create, fill, and print set with normal element order
    IntSet coll1 = {4,7,5,1,6,2,5};
    PRINT_ELEMENTS(coll1, "coll1: ");

    //create soring criterion with reverse element order
    RuntimeCmp reverse_order(RuntimeCmp::reverse);

    //create, fill and print set with reversed order
    IntSet coll2(reverse_order);
    coll2.insert(coll1.cbegin(), coll1.cend());
    PRINT_ELEMENTS(coll2, "coll2: ");

    //assign elements AND sorting criterion
    coll1 = coll2;
    coll1.insert(3);
    PRINT_ELEMENTS(coll1, "coll1: ");

    //just to make sure
    //value_comp() : Returns the comparison criterion for values as a whole (same as key_comp())
    if(coll1.value_comp() == coll2.value_comp()){
        cout << "coll1 and coll2 have the same sorting criterion" << endl;
    }else{
        cout << "coll1 and coll2 have different sorting criterions" << endl;
    }
    return 0;
}
