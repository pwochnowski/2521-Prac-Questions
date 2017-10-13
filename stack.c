// stack.c ... simple Stack of Strings
// Written by John Shepherd, September 2015

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "Stack.h"

typedef struct Node *Link;

typedef struct Node {
	int val;
	Link  next;
} Node;
	
typedef struct StackRep {
	Link  top;
} StackRep;

// Function signatures

Stack newStack();
void  disposeStack(Stack);
void  pushOnto(Stack,int );
int popFrom(Stack);
int   emptyStack(Stack);
void  showStack(Stack s);

static Link newNode(int );
static void disposeNode(Link);


// newStack()
// - create an initially empty Stack
Stack newStack()
{
	Stack new = malloc(sizeof(StackRep));
	assert(new != NULL);
	new->top = NULL;
	return new;
}

// disposeStack(Stack)
// - clean up memory associated with Stack
void disposeStack(Stack s)
{
	if (s == NULL) return;
	Link next, curr = s->top;
	while (curr != NULL) {
		next = curr->next;
		disposeNode(curr);	
		curr = next;
	}
}

// pushOnto(Stack,Str)
// - add Str to top of Stack
void pushOnto(Stack s, int str)
{
	Link new = newNode(str);
	new->next = s->top;
	s->top = new;
}

// popFrom(Stack)
// - return string from top of Stack
int popFrom(Stack s)
{
	assert (s != NULL && s->top != NULL);
    int str = s->top->val;
	Link old = s->top;
	s->top = old->next;
	free(old);
	return str;
}

// emptyStack(Stack)
// - check whether Stack is empty
int emptyStack(Stack s)
{
	return (s->top == NULL);
}

// showStack(Stack)
// - display Stack (for debugging)
void showStack(Stack s)
{
	Link curr;
	if (s->top == NULL)
		printf("Stack is empty\n");
	else {
		printf("Stack (top-to-bottom):\n");
		int id = 0;
		curr = s->top;
		while (curr != NULL) {
			printf("[%03d] %d\n", id, curr->val);
			id++;
			curr = curr->next;
		}
	}
}

// Helper functions

static Link newNode(int str)
{
	Link new = malloc(sizeof(Node));
	assert(new != NULL);
        new->val = str;
	new->next = NULL;
	return new;
}

static void disposeNode(Link curr)
{
	assert(curr != NULL);
	free(curr);
}

