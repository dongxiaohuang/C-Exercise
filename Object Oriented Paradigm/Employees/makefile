OBJ = main.o Employee.o Manager.o PC.o Desk.o Office.o Boss.o EmployeeList.o
CXXFLAGS = -Wall -g -std=c++11 -MMD

main: $(OBJ)
	g++ $(OBJ) -o main
%.o: %.cpp
	g++ $(CXXFLAGS) -c $<
-include $(OBJ:.o=.d)
clean:
	rm -f main *.o *.d
.PHONEY: clean
