
CC=g++
FLAGS=-std=c++17 -pedantic -Wall -Wextra -Wno-unused-variable -fsanitize=address
OUTPUT=lab6
TEST_OUTPUT=runner

all: super_alg.o
	$(CC) $(FLAGS) super_alg.o lab6.cpp -o $(OUTPUT)

test: super_alg.o
	$(CC) $(FLAGS) -lcppunit super_alg.o runner.cpp -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)

super_alg.o: super_alg.hpp super_alg.cpp
	$(CC) $(FLAGS) -c super_alg.cpp

clean:
	rm -f $(OUTPUT) $(TEST_OUTPUT) *.o
