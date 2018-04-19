OBJ = main.o setcmp.o
CXXFLAGS = -Wall -g -std=c++11 -MMD


setcmp: setcmp.o
	g++ setcmp.o -o setcmp
main: main.o
	g++ main.o -o main
%.o: %.cpp
	g++ $(CXXFLAGS) -c $<

-include $(OBJ:.o=.d)

clean:
	rm -f main *.o
.PHONEY: clean
