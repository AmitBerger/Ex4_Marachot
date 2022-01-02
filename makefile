CC = gcc
AR = ar
FLAGS = -Wall -g

make all: libgraph.so run

libgraph.so: GraphAlgo.o PQ.o
	$(CC) -shared -o libgraph.so GraphAlgo.o PQ.o
	
main.o: GraphAlgo.h main.c
	$(CC) $(FLAGS) -c main.c

PQ.o: PQ.h graph.h PQ.c
	$(CC) $(FLAGS) -c PQ.c

GraphAlgo.o: GraphAlgo.h graph.h  PQ.h GraphAlgo.c
	$(CC) $(FLAGS) -c GraphAlgo.c

run: main.o libgraph.so
	$(CC) $(FLAGS) -o run main.o ./libgraph.so

.PHONY: clean all
clean: 
	rm -f *.o *.so libgraph.so run
