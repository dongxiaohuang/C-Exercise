#include "HardDisk.h"

HardDisk::HardDisk(double capacity, double bandwidth, double rotation, double seek):
     StorageDevice(capacity, bandwidth), _average_rotation(rotation), _average_seek(seek){}

double HardDisk::latency() const{
     return _average_rotation + _average_seek;
}
