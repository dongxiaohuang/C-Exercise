OBJ = main.o
CXXFLAGS = -Wall -g -Wall -MMD -std=c++11

main: $(OBJ)
	g++ $(OBJ) -o main

%.o: %.cpp
	g++ $(CXXFLAGS) -c $<
-include ($(OBJ:.o=.d))

clean:
	rm -f main *.o
.PHONEY:clean
