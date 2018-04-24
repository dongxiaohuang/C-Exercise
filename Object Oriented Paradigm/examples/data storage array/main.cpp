#include <iostream>
#include "RAID1StorageArray.h"
#include "RAID5StorageArray.h"
#include "HardDisk.h"
#include "SolidStateDisk.h"
using namespace std;
int main(){

     RAID1StorageArray r1;
     Raid5StorageArray r5;
     // HardDisk* h = new HardDisk[4](500, 100, 4, 8);

     for(int i = 0; i < 4; i++){
          r1.add(new HardDisk(500, 100, 4, 8));
     }

     for(int i = 0; i < 4; i++){
          r5.add(new SolidStateDisk(30, 300, 0.01));
     }

     cout << "RAID1 bandwidth() : "<<r1.bandwidth() << endl;
     cout << "RAID1 latency() : "<<r1.latency() << endl;
     cout << "RAID1 capacity() : "<<r1.capacity() << endl;
     cout << "RAID5 capacity() : "<<r5.capacity() << endl;

     return 0;
}
