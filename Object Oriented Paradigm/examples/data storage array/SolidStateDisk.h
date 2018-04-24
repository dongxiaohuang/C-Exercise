#ifndef SOLID_STACK_DISK_H
#define SOLID_STACK_DISK_H
#include "StorageDevice.h"

class SolidStateDisk : public StorageDevice {
private:
     const double _memory_access_time;
public:
     SolidStateDisk(double capacity, double bandwidth, double mat);
     double latency() const override;
};
#endif
