#ifndef HELPER_H
#define HELPER_H

class Helper
{
  static int number; // intialize in .cpp file
  const int ID; // must intialize by constructor :
public:
  Helper(int id);
  ~Helper();
  static int getNum(){return number;}
  int getID() const; // const is behind the ()
  int showId();

};
#endif
