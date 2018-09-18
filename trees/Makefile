# Steven Strijakov's Fun Quizzes for Fun
# Week12

CC=gcc
CFLAGS=-Wall -Werror -gdwarf-2
CC=gcc

EXEC = solution
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(EXEC) $(OBJECTS)
