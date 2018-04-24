#ifndef STORAGE_DEVICE_H
#define STORAGE_DEVICE_H
class StorageDevice {
private:
     /* data */
protected:
     const double _capacity;
     const double _bandwidth;
public:
     StorageDevice (double capacity, double bandwidth);
     virtual double latency() const = 0;
     double capacity() const;
     double bandwidth() const;
     virtual ~StorageDevice();
};
#endif
