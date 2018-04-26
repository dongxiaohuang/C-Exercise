#ifndef PAF_H
#define PAF_H
#include "AF.h"
class PAF : public AF{
private:
     /* data */
     float _programming_mark;
public:
     PAF (string name, int year, float os_mark, float nw_mark);
     float calculateScore() override;
};
#endif
