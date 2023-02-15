CC = g++

CFLAGS = -c -Wall -Wextra 

all : Queue

Queue : queue_functions.o  queue.o
	$(CC) queue_functions.o  queue.o  -o Queue

queue_functions.o : queue_functions.cpp
	$(CC) $(CFLAGS) $^
	
queue.o : queue.cpp
	$(CC) $(CFLAGS) $^

clean:
	rm -rf *.o Queue

rebuild: clean all

