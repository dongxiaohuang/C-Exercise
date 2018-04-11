OBJ = main.o
CXXFLAGS = -Wall -g -MMD
main : $(OBJ)
	g++ $(OBJ) -o main
%.o : %.cpp
	g++ $(CXXFLAGS) -c $<
-include $(OBJ:.o=.d)

clean:
	rm -f $(OBJ) $(OBJ:.o=.d) main
.PHONEY: clean
