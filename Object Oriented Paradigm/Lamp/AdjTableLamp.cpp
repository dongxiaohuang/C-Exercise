#include "AdjTableLamp.h"

AdjTableLamp::AdjTableLamp(){
    brightness = 1.0;
}
void AdjTableLamp::dim(){
    if(brightness > 0.1)
        brightness -= 0.1;
}

std::ostream& operator<< (std::ostream& o, const AdjTableLamp& at){
    return o << (TableLamp) at << " with brightness: "<< at.brightness << std::endl;
}
