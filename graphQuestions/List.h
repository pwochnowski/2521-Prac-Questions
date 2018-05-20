// List.h - Lists of integers (interface)
// Written by John Shepherd, July 2008

#ifndef INTLIST_H
#define INTLIST_H

#include <stdio.h>

// External view of List
// Implementation given in intList.c

typedef struct ListRep *List;


typedef struct ListNode {
	int  data;  // value of this list item
	struct ListNode *next;
	            // pointer to node containing next element
} ListNode;

struct ListRep {
	int  size;  // number of elements in list
	struct ListNode *first;
	            // node containing first value
	struct ListNode *last;
	            // node containing last value
};
// create a new empty List
List newList();

// free up all space associated with list
void freeList(List);

// create an List by reading values from a file
// assume that the file is open for reading
List getList(FILE *);

// display list as one integer per line on stdout
void showList(List);

// apppend one integer to the end of a list
void ListInsert(List, int);

// insert an integer into correct place in a sorted list
void ListInsertInOrder(List, int);

// delete first occurrence of v from a list
// if v does not occur in List, no effect
void ListDelete(List, int);

// return number of elements in a list
int ListLength(List);

// make a physical copy of a list
// new list looks identical to original list
List ListCopy(List);

// make a sorted physical copy of a list
List ListSortedCopy(List);

// check whether a list is sorted in ascending order
// returns 0 if list is not sorted, returns non-zero if it is
int ListIsSorted(List);

// check sanity of an List
int ListOK(List);

// display list as one integer per line to a file
// assume that the file is open for writing
void ListPrint(FILE *, List);

#endif
