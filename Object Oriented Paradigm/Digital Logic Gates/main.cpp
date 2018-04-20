#include "Source.h"
#include "And.h"
#include "Or.h"
int main(int argc, char const *argv[]) {
    /* code */
    Source s1("S1", 0);
    Source s2("S2", 0);
    Source s3("S3", 0);
    And and1("And1", &s1, &s2);
    Or or1("Or", &and1, &s3);

    or1.print();
    cout << " = "<<  or1.state()<<endl;
    return 0;
}
