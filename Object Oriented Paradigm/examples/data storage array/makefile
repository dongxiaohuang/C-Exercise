OBJ = main.o StorageArray.o StorageDevice.o RAID1StorageArray.o HardDisk.o SolidStateDisk.o RAID5StorageArray.o
CXXFLAGS = -Wall -g -MMD -std=c++11
# make sure add all the class into compiler enve if they are not used in main
main: $(OBJ)
	g++ $(OBJ) -o main
%.o: %.cpp
	g++ $(CXXFLAGS) -c $<
-include $(OBJ:.o=.d)
clean:
	rm -f *.d *.o main
.PHONEY: clean
