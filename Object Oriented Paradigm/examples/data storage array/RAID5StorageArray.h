#ifndef RAID5STORAGEARRAY_H
#define RAID5STORAGEARRAY_H
#include "StorageArray.h"

class Raid5StorageArray :public StorageArray {
private:
     /* data */
protected:
     double scale_factor() const override;
public:
     Raid5StorageArray(){};
     ~Raid5StorageArray(){}
};
#endif
