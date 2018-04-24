#include "Course.h"
#include "Map.h"
#include "Textbook.h"
int courseCompare(const Course* const& a, const Course* const& b){
    return a ->getCode() - b ->getCode();
}
int main(int argc, char const *argv[]) {
    /* code */
    Course* oo = new Course( "OO Design & Prog", 517 ),
        * cs = new Course ( "Computer Systems", 515),
        * lg = new Course (" Logic & AI Prog", 518 );

    Textbook* ps =new Textbook (" Problem Solving w/ C++", 11),
        *ca = new Textbook (" Computer Architecture", 33),
        *cd = new Textbook (" C++ for Dummies", 55);

    cout << oo << cs << ps;

    Map<const Course*, Textbook*, courseCompare> ctm;
    ctm.insert(oo, ps);
    ctm.insert(cs, ca);
    Textbook** result = ctm.get(oo);
    cout << result;
    delete oo;
    delete cs;
    delete lg;
    delete ps;
    delete ca;
    delete cd;
    return 0;
}
