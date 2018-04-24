#ifndef RAID1RAID5STORAGEARRAY_H
#define RAID1RAID5STORAGEARRAY_H
#include "StorageArray.h"
class RAID1StorageArray : public StorageArray {
private:
     /* data */
protected:
     double scale_factor() const override;
public:
     RAID1StorageArray (){};
     virtual ~RAID1StorageArray (){}
};
#endif
