# SENG 330 assignment 1 C++ implementation

CC=g++
CFLAGS=-Wall -g -c

all: tests player.o team.o league.o

tests: tests.o player.o team.o league.o
	$(CC) player.o team.o league.o tests.o -o tests

tests.o: tests.cpp
	$(CC) $(CFLAGS) tests.cpp
	
player.o: hockey.h player.h player.cpp 
	$(CC) $(CFLAGS) player.cpp
	
team.o: hockey.h player.h team.h team.cpp
	$(CC) $(CFLAGS) team.cpp
	
league.o: hockey.h team.h league.cpp
	$(CC) $(CFLAGS) league.cpp
	
clean:
	rm *.o tests
