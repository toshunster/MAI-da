CXX = g++
CXXFLAGS = -std=c++20 -pedantic -Wall -Wextra -Werror

all: lab2 lab2_test lab2_profiler

lab2: lab2.cpp bst.hpp
	$(CXX) $(CXXFLAGS) lab2.cpp -o lab2

lab2_test: test.cpp bst.hpp
	$(CXX) $(CXXFLAGS) test.cpp -o lab2_test

lab2_profiler: lab2.cpp
	$(CXX) $(CXXFLAGS) -pg lab2.cpp -o lab2_profiler

test:
	./lab2_test

clean:
	rm -f lab2 lab2_profiler lab2_test *.o
