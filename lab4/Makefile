CC = g++
CC_FLAGS = -std=c++14 -pedantic -Wall
OBJS = utils.o

all: $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) lab4.cpp -o lab4
utils.o: utils.cpp
	$(CC) $(CC_FLAGS) -c utils.cpp
clean:
	rm -f $(OBJS) lab4
