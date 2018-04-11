OBJ = main.o binary_search.o sequential_search.o \
interpolation_search.o

CXXFLAGS = -Wall -g -MMD -std=c++11

main: $(OBJ)
	g++ $(OBJ) -o main
%.o: %.cpp	g++ $(CXXFLAGS) -c $<
-include $(OBJ:.o=.d)
clean:
	rm -f main $(OBJ) $(OBJ.o=.d)
.PHONEY:clean
