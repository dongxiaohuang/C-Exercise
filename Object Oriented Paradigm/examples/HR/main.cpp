#include "HR.h"
#include "NAF.h"
#include "PAF.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
     HR Helen("Helen", 1975, 50);
     NAF naf("Peter", 1986, 60, 75);
     PAF paf("Susan", 1989, 70, 60);
     NAF naf1("Susan", 1989, 70, 80);
     NAF naf2("Susan", 1989, 70, 80);
     NAF naf3("Susan", 1989, 70, 80);
     NAF naf4("Susan", 1989, 70, 80);
     NAF naf5("Susan", 1989, 70, 80);
     Helen.receive(&naf1);
     Helen.receive(&naf2);
     Helen.receive(&naf3);
     Helen.receive(&naf4);
     Helen.receive(&naf5);
     Helen.receive(&naf);
     Helen.receive(&naf2);
     Helen.receive(&paf);
     cout << Helen.count() << endl;
     Helen.remove();
     cout << "in total : " << Helen.count() << endl;
     return 0;
}
