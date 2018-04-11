OBJ = main.o stack.o
CXXFLAGS = -g -Wall -MMD -std=c++11

main: $(OBJ)
	g++ $(OBJ) -o main

%.o: %.cpp
	g++ $(CXXFLAGS) -c $<

-include $(OBJ:.o=.d)

clean:
	rm -f $(OBJ:.o=.d) main $(OBJ)

.PHONEY: clean
