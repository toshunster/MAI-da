
CC=g++
FLAGS=-std=c++14 -pedantic -Wall -Wextra -Wno-unused-variable
OUTPUT=lab1

all: sort.o vector.o lab1.cpp
	$(CC) $(FLAGS) sort.o vector.o lab1.cpp -o $(OUTPUT)
sort.o: sort.cpp sort.hpp
	$(CC) $(FLAGS) -c sort.cpp
vector.o: vector.cpp vector.hpp
	$(CC) $(FLAGS) -c vector.cpp
benchmark: sort.o vector.o benchmark.cpp
	$(CC) $(FLAGS) sort.o vector.o benchmark.cpp -o benchmark
clean:
	rm *.o $(OUTPUT)
