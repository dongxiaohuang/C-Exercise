#ifndef NAF_H
#define NAF_H
#include "AF.h"

class NAF : public AF {
private:
     /* data */
     float _network_mark;
public:
     NAF (string name, int year, float os_mark, float nw_mark);
     float calculateScore() override;
};
#endif
