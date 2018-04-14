OBJ=main.o
CXXFLAGS = -Wall -g -std=c++11 -MMD
main: $(OBJ)
	g++ $(OBJ) -o main
%.o: %.cpp
	g++ $(CXXFLAGS) -c $<

-include $(OBJ:.o=.d)
clean:
	rm -f *.o main
.PHONEY:clean
