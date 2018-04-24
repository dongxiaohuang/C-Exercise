#ifndef STORAGEARRAY_H
#define STORAGEARRAY_H
#include "StorageDevice.h"
class StorageArray {
private:
     /* data */
     StorageDevice* _device_arr[12];
     double total_capacity() const;
protected:
     int device;
     double total_bandwidth() const;
     virtual double scale_factor() const = 0;
public:
     StorageArray (){ device = 0;}
     bool add(StorageDevice* sa);
     double latency() const;
     double bandwidth() const;
     double capacity() const;
     ~StorageArray ();
};
#endif
