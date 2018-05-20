// List.c - Lists of integers
// Written by John Shepherd, July 2008

#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "List.h"

// data structures representing List

// create a new empty List
List newList()
{
	struct ListRep *L;

	L = malloc(sizeof (struct ListRep));
	assert (L != NULL);
	L->size = 0;
	L->first = NULL;
	L->last = NULL;
	return L;
}

// free up all space associated with list
void freeList(List L)
{
  ListNode *it = L->first;
  ListNode *tmp;
  while (it) {
    tmp = it;
    it = it->next;
    free(tmp);
  }
  free(L);
}

// display list as one integer per line on stdout
void showList(List L)
{
	ListPrint(stdout, L);
}

// create an List by reading values from a file
// assume that the file is open for reading
List getList(FILE *inf)
{
	List L;
	int v;

	L = newList();
	while (fscanf(inf,"%d",&v) != EOF)
		ListInsert(L,v);
	return L;
}

// create a new ListNode with value v
// (this function is local to this ADT)
static struct ListNode *newListNode(int v)
{
	struct ListNode *n;

	n = malloc(sizeof (struct ListNode));
	assert(n != NULL);
	n->data = v;
	n->next = NULL;
	return n;
}

// apppend one integer to the end of a list
void ListInsert(List L, int v)
{
	struct ListNode *n;

	assert(L != NULL);
	n = newListNode(v);
	if (L->first == NULL)
		L->first = L->last = n;
	else {
		L->last->next = n;
		L->last = n;
	}
	L->size++;
}

// insert an integer into correct place in a sorted list
void ListInsertInOrder(List L, int v)
{
	// This is INCORRECT
	ListInsert(L, v);
}

// delete first occurrence of v from a list
// if v does not occur in List, no effect
void ListDelete(List L, int v)
{
	struct ListNode *curr, *prev;

	assert(L != NULL);

	// find where v occurs in list
	prev = NULL; curr = L->first;
	while (curr != NULL && curr->data != v) {
		prev = curr;
		curr = curr->next;
	}
	// not found; give up
	if (curr == NULL) return;
	// unlink curr
	if (prev == NULL)
		L->first = curr->next;
	else
		prev->next = curr->next;
	if (L->last == curr)
		L->last = prev;
	L->size--;
	// remove curr
	free(curr);
}

// return number of elements in a list
int ListLength(List L)
{
	assert(L != NULL);
	return L->size;
}

// make a physical copy of a list
// new list looks identical to original list
List ListCopy(List L)
{
	struct ListRep *Lnew;
	struct ListNode *curr;

	Lnew = newList();
	for (curr = L->first; curr != NULL; curr = curr->next)
		ListInsert(Lnew, curr->data);
	return Lnew;
}

// make a sorted physical copy of a list
List ListSortedCopy(List L)
{
	struct ListRep *Lnew;
	struct ListNode *curr;

	Lnew = newList();
	for (curr = L->first; curr != NULL; curr = curr->next)
		ListInsertInOrder(Lnew, curr->data);
	return Lnew;
}

// check whether a list is sorted in ascending order
// returns 0 if list is not sorted, returns non-zero if it is
int ListIsSorted(List L)
{
	struct ListNode *curr;

	assert(L != NULL);
	// trivial cases, 0 or 1 items
	if (L->size < 2)
		return 1;
	// scan list, looking for out-of-order pair
	for (curr = L->first; curr->next != NULL; curr = curr->next) {
		if (curr->next->data < curr->data)
			return 0;
	}
	// nothing out-of-order, must be sorted
	return 1;
}

// check sanity of an List (for debugging)
int ListOK(List L)
{
	struct ListNode *p;
	int count;

	if (L == NULL)
		return 1;
	if (L->size == 0)
		return (L->first == NULL && L->last == NULL);

	// scan to (but not past) last node
	count = 1; // at least one node
	for (p = L->first; p->next != NULL; p = p->next)
		count++;

	return (count == L->size && p == L->last);
}

// display list as one integer per line to a file
// assume that the file is open for writing
void ListPrint(FILE *outf, List L)
{
	struct ListNode *curr;

	assert(L != NULL);
	for (curr = L->first; curr != NULL; curr = curr->next)
		printf("%d\n", curr->data);
}
