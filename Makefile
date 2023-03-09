CC = g++

CFLAGS = -c -Wall -Wextra 

all : Queue

Queue : queue_functions.o  main.o
	$(CC) queue_functions.o  main.o  -o Queue

queue_functions.o : queue_functions.cpp
	$(CC) $(CFLAGS) $^
	
main.o : main.cpp
	$(CC) $(CFLAGS) $^

clean:
	rm -rf *.o Queue

rebuild: clean all

