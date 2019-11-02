CC = g++
FLAGS = -std=c++14 -Wall -pedantic
OBJS = trie.o

all: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) main.cpp -o trie
trie.o: trie.cpp trie.hpp
	$(CC) $(FLAGS) -c trie.cpp
clean:
	rm -f trie $(OBJS)
