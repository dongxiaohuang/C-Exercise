OBJ = main.o
CXXFLAGS = -Wall -g -MMD -std=c++11

main: $(OBJ)
	g++ $(OBJ) -o main

%.o: %.cpp
	g++ $(CXXFLAGS) -c $<

-include ($(OBJ:.o=.d)

clean:
	rm -f mian *.d *.o

.PHONEY: clean
