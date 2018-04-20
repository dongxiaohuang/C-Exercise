#include "AlarmDoor.h"

int main(int argc, char const *argv[]) {
    AlarmDoor ad(2282);
    ad.open();
    ad.enterCode(222);
    ad.enterCode(2282);
    ad.open();
    // so far AlarmDoor cannot use any base class function
    //except one isActive() because we change its scope
    cout << "state : " << ad.isActive() << endl;
    return 0;
}
