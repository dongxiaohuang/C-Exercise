#ifndef TEXTBOOK_H
#define TEXTBOOK_H

#include <iostream>
using namespace std;
class Textbook {
private:
    /* data */
    const char* _name;
    const int _id;
public:
    Textbook (const char* name, const int id);
    int getId() const;
    const char* getTitle() const;
    // virtual ~Textbook (){};
    friend ostream& operator<< (ostream& o, const Textbook* textbook);
};

#endif
