#include "StorageDevice.h"
StorageDevice::StorageDevice(double capacity, double bandwidth):
     _capacity(capacity), _bandwidth(bandwidth){}

double StorageDevice::capacity() const{
     return _capacity;
}
double StorageDevice::bandwidth() const{
     return _bandwidth;
}
StorageDevice::~StorageDevice (){}
