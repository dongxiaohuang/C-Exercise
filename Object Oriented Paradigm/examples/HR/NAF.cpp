#include "NAF.h"

NAF::NAF(string name, int year, float os_mark, float nw_mark):
     AF(name, year, os_mark), _network_mark(nw_mark){}
float NAF::calculateScore(){
     return (_network_mark + _os_mark)/2;
}
