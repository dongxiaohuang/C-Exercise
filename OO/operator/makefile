OBJ = main.o test.o week.o self_up_dow.o
CXXFLAGS = -Wall -g -MMD -std=c++11

main: $(OBJ)
	g++ $(OBJ) -o main
%.o: %.cpp	g++ $(CXXFLAGS) -c $<
-include $(OBJ:.o=.d)
clean:
	rm -f main $(OBJ) $(OBJ.o=.d)
.PHONEY:clean
