CC = g++
FLAGS = -std=c++14 -Wall -pedantic
OBJS = bst.o

all: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) lab2.cpp -o lab2
benchmark: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) benchmark.cpp -o benchmark
bst.o: bst.cpp bst.hpp
	$(CC) $(FLAGS) -c bst.cpp
clean:
	rm -f lab2 $(OBJS)
