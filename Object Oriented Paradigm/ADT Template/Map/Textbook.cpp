#include "Textbook.h"
Textbook::Textbook(const char* name, const int id)
    : _name(name), _id(id){}

int Textbook::getId() const {return _id;}

const char* Textbook::getTitle() const {return _name;}
ostream& operator<< (ostream& o, const Textbook* textbook){
    return o << "Textbook " << textbook -> getId() <<": "
        << textbook -> getTitle() << endl;
}
