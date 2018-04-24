#ifndef HARDDISK_H
#define HARDDISK_H
#include "StorageDevice.h"
class HardDisk : public StorageDevice {
private:
     /* data */
     const double _average_rotation;
     const double _average_seek;
public:
     HardDisk (double capacity, double bandwidth, double rotation, double seek);
     double latency() const override;
     virtual ~HardDisk (){};
};
#endif
