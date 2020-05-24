CXX = g++
CXXFLAGS = -Wall

proj0: driver.o 
	$(CXX) $(CXXFLAGS) driver.o -o proj0


driver.o: stack.h driver.cpp
	$(CXX) $(CXXFLAGS) -c driver.cpp


clean:
	rm *.o proj0
	rm *~
