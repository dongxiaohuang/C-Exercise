OBJ = main.o helper.o bubblesort.o simple_selection.o \
 			straight_insertion.o shell_sort.o heap_sort.o \
			merging_sort.o quick_sort.o
CXXFLAGS = -Wall -g -MMD -std=c++11

main: $(OBJ)
	g++ $(OBJ) -o main

%.o: %.cpp
	g++ $(CXXFLAGS) -c $<

-include $(OBJ:.o=.d)
clean:
	rm -f main $(OBJ) $(OBJ:.o=.d)
.PHONEY: clean
