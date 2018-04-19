#include "TableLamp.h"

TableLamp::TableLamp(){
    state = OFF;
}
void TableLamp::pressSwitch(){
     state = ((state == ON) ? OFF : ON);
}

std::ostream& operator<< (std::ostream& o, const TableLamp& t){
    return o << ((t.state == TableLamp::ON ) ?
        " is on!" : " is off!");
}
