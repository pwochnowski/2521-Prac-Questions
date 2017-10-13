# Makefile for stuff 

CC=gcc
CFLAGS=-Wall -Werror 
LIBS=Queue.o Graph.o Stack.o

test : testGraph.o $(LIBS)
	gcc -o runtests testGraph.o $(LIBS) 


Queue.o : Queue.c Queue.h
Stack.o : Stack.c Stack.h
Graph.o : Graph.c Graph.h

ts : ts.o set.o
	gcc -o ts ts.o set.o
ts.o : ts.c set.h

tq : tq.o queue.o
	gcc -o tq tq.o queue.o
tq.o : tq.c queue.h

tk : tk.o stack.o
	gcc -o tk tk.o stack.o
tk.o : tk.c stack.h

tg : tg.o graph.o
	gcc -o tg tg.o graph.o
tg.o : tg.c graph.h

clean :
	rm -f crawl $(TESTS) *.o core
