CC = gcc
AR = ar
FLAGS = -Wall -g

make all: libgraph.so graph

libgraph.so: GraphAlgo.o PQ.o
	$(CC) -shared -o libgraph.so GraphAlgo.o PQ.o

main.o: GraphAlgo.h main.c
	$(CC) $(FLAGS) -c main.c

PQ.o: PQ.h graph.h PQ.c
	$(CC) $(FLAGS) -c PQ.c

GraphAlgo.o: GraphAlgo.h graph.h PQ.h PQ.h GraphAlgo.c
	$(CC) $(FLAGS) -c GraphAlgo.c

graph: main.o libgraph.so
	$(CC) $(FLAGS) -o graph main.o ./libgraph.so

.PHONY: clean all
clean: 
	rm -f *.o *.so libgraph.so graph 
