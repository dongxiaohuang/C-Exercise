#include "StorageArray.h"
#include <iostream>
bool StorageArray::add(StorageDevice* sa){
     if(device >= 12)
          return false;
     _device_arr[device++] = sa;
     return true;
}

double StorageArray::total_bandwidth() const{
     double total_bandwidth = 0;
     for(int i = 0; i < device; i++ ){
          total_bandwidth += _device_arr[i] ->bandwidth();
     }
     return total_bandwidth;
}
double StorageArray::latency() const{
     double max_latency = 0;
     for(int i = 0; i < device; i++ ){
          if(max_latency <_device_arr[i] ->latency()){
               max_latency = _device_arr[i] ->latency();
          }
     }
     return max_latency;
}
double StorageArray::total_capacity() const{
     double total_capacity = 0;
     for(int i = 0; i < device; i++ ){
          total_capacity += _device_arr[i] ->capacity();
     }
     return total_capacity;
}
double StorageArray::capacity() const{
     return scale_factor()*total_capacity();
}
double StorageArray::bandwidth() const{
     return scale_factor()*total_bandwidth();
}
StorageArray::~StorageArray(){
     for(int i = 0; i < device; i++)
     delete _device_arr[i];
}
