#include "AdjTableLamp.h"
#include "TableLamp.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
        /* static binding */
        AdjTableLamp myLamp;
        cout << " myLamp" << myLamp;
        myLamp.dim ();
        cout << " myLamp" <<myLamp;
        myLamp.pressSwitch ();
        cout << " myLamp" << myLamp;

        TableLamp yourLamp;
        AdjTableLamp* hisLamp = new AdjTableLamp ();
        //yourLamp.dim;             illegal!

        cout << "hisLamp " << *hisLamp;
        hisLamp->dim();
        cout << "hisLamp " << *hisLamp;
        hisLamp->pressSwitch();
        cout << "hisLamp " << *hisLamp;

        TableLamp* herLamp = new TableLamp();
        //herLamp -> dim();         illegal!
        cout << "herLamp " << *herLamp << endl;

        //Implicit conversion
        delete herLamp;
        //assignment and inheritance : Pointers
        TableLamp* herLamp2 = hisLamp;//OK!
        cout << "herLamp2" << *herLamp2 << endl;
        // hisLamp = &yourLamp;    illegal! because it does not have derived functions and members
        hisLamp->pressSwitch();
        cout << "herLamp2" << *herLamp2 << endl;
        cout << "hisLamp" << *hisLamp << endl;
        // herLamp2 is off

        // herLamp2 -> dim();  illegal

        // assignment and inheritance : Objects
        yourLamp = myLamp; // copy shared attributes
        cout << "yourLamp " << yourLamp;
        myLamp.pressSwitch();
        cout << "yourLamp " << yourLamp << endl;
        cout << "myLamp " << myLamp;

        // assignment and inheritance : References
        AdjTableLamp& myLampRef = myLamp;
        TableLamp& yourLampRef = yourLamp;

        myLampRef.pressSwitch();
        yourLampRef.pressSwitch();
        cout << "yourLamp " << yourLampRef << endl;
        cout << "myLamp " << myLampRef << endl;

        yourLamp = myLamp; // copy
        cout << "yourLamp " << yourLampRef << endl;
        myLamp.pressSwitch();
        cout << "yourLamp " << yourLampRef << endl;
        cout << "myLamp " << myLamp << endl;

        delete hisLamp;
        // delete herLamp2; // very bad //Deleter her lamp instead in cpp is undefined because it is a table lamp class
        return 0;
}
