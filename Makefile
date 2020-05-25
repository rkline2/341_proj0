CXX = g++
CXXFLAGS = -Wall

proj0: driver.o mytest.o
	$(CXX) $(CXXFLAGS) driver.o mytest.o -o proj0


driver.o: stack.h driver.cpp
	$(CXX) $(CXXFLAGS) -c driver.cpp


mytest.o: stack.h mytest.cpp
	$(CXX) $(CXXFLAGS) -c mytest.cpp


clean:
	rm *.o proj0
	rm *~
