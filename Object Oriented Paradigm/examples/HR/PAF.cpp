#include "PAF.h"

PAF::PAF(string name, int year, float os_mark, float p_mark):
     AF(name, year, os_mark), _programming_mark(p_mark){}
float PAF::calculateScore(){
     return (_programming_mark + _os_mark)/2;
}
