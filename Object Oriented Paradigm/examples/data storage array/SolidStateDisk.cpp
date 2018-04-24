#include "SolidStateDisk.h"

SolidStateDisk::SolidStateDisk(double capacity, double bandwidth,
     double mat) : StorageDevice(capacity, bandwidth), _memory_access_time(mat){}
double SolidStateDisk::latency() const{
     return _memory_access_time;
}
