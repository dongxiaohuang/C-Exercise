OBJ = main.o linkedList.o testPointer.o
CXXFLAGS = -Wall -g -MMD

main: $(OBJ)
	g++ $(OBJ) -o main
%.o: %.cpp
	g++ $(CXXFLAGS) -c $<
-include $(OBJ:.o=.d)
clean:
	rm -f main $(OBJ) $(OBJ:.o=.d)
.PHONEY: clean
