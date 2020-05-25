CXX = g++
CXXFLAGS = -Wall

proj0: driver.o test.o
	$(CXX) $(CXXFLAGS) driver.o test.o -o proj0


driver.o: stack.h driver.cpp
	$(CXX) $(CXXFLAGS) -c driver.cpp


test.o: stack.h mytest.cpp
	$(CXX) $(CXXFLAGS) -c mytest.cpp


clean:
	rm *.o proj0
	rm *~
