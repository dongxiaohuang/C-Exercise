#include "RAID5StorageArray.h"
#include <iostream>
double Raid5StorageArray::scale_factor() const{
     return (device-1.0)/device;
}
