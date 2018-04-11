#ifndef INFO_H
#define INFO_H

class Info
{
public:
  Info();
  Info(int i);
  Info(char c);
  virtual ~Info();
  void print();
  // Info(const Info& src);
  void func1(Info i);
  Info func2();
  friend void change_i_val(int another_i, Info &info);
private:
  void Init();
  int id = 2016;
  char gender{'M'}; //== gender = 'M'
};

auto func3() -> int;

void change_i_val(int another_i, Info &info);
#endif
