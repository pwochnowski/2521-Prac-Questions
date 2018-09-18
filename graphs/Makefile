# Makefile for stuff 

CC=gcc
CFLAGS=-Wall -Werror 
LIBS=Queue.o Graph.o Stack.o List.o

test : testGraph.o $(LIBS)
	gcc -o runtests testGraph.o $(LIBS) 


List.o : List.c List.h
Queue.o : Queue.c Queue.h
Stack.o : Stack.c Stack.h
Graph.o : Graph.c Graph.h

clean :
	rm -f runtests $(TESTS) *.o core
