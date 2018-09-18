#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Graph.h"
#include "Stack.h"
#include "Queue.h"
#include "List.h"

void testWithin() {
  Graph g = newGraph(6);
  insertBEdge(g,0,1,1); 
  insertBEdge(g,2,1,1); 
  insertBEdge(g,3,1,1); 
  insertBEdge(g,4,1,1); 
  insertBEdge(g,5,1,1); 
  int i, j;
  int n = 0; 
  int* res = within(g,1,1,&n);
  assert(n == 6);
  assert(res[0]==1);
  for (i=5,j=1; i>=0; i--){
    if (i==1) continue;
    assert( res[j++] == i);
  }
  free(res);

  res = within(g,5,1,&n);
  assert(n == 2);
  assert(res[0] == 5);
  assert(res[1] == 1);
  free(res);

  dropGraph(g);
  printf("Passed tests for within!\n");
}

void testBipartition() {
  Graph g = newGraph(7);
  List l1 = newList();
  List l2 = newList();
  insertBEdge(g,1,2,1);
  insertBEdge(g,1,4,1);
  insertBEdge(g,2,5,1);
  insertBEdge(g,5,6,1);
  insertBEdge(g,3,0,1);
  insertBEdge(g,3,4,1);

  assert(bipartition(g,l1,l2) == 1);
  assert(ListLength(l1) + ListLength(l2) == 7);

  int* check = malloc(6*sizeof(int));
  ListNode *it;
  ListNode *tmp;
  //Check that lists are disjoint 
  it = l1->first;
  while (it) {
    check[it->data] = 1;
    tmp = l1->first;
    while (tmp) {
      if (tmp != it) {
        assert(adjacent(g,tmp->data,it->data) == 0);
        assert(adjacent(g,it->data,tmp->data) == 0);
      }
      tmp = tmp->next;
    }
    it= it->next;

  }

  it = l2->first;
  while (it) {
    check[it->data] = 1;
    tmp = l2->first;
    while (tmp) {
      if (tmp != it) {
        assert(adjacent(g,tmp->data,it->data) == 0);
        assert(adjacent(g,it->data,tmp->data) == 0);
      }
      tmp = tmp->next;
    }
    it= it->next;
  }
  int i;
  for (i=0; i<6; i++) {
    assert(check[i] != 0);
  }
  freeList(l1);
  freeList(l2);
  dropGraph(g);
  g = newGraph(3);
  insertBEdge(g,0,1,1);
  insertBEdge(g,1,2,1);
  insertBEdge(g,2,0,1);
  l1 = newList(); 
  l2 = newList();
  assert(bipartition(g,l1,l2) == 0);
  freeList(l1);
  freeList(l2);
  dropGraph(g);
  
  printf("Passed all tests for bipartition!!!\n");
}

void testCycle() {
  Graph g = newGraph(4);
  insertBEdge(g,0,1,1);
  insertBEdge(g,0,2,1);
  insertEdge(g,0,3,1); //undirected edge from 0 to 3
  assert(hasCycle(g) == 0);
  dropGraph(g);

  g = newGraph(3);
  insertBEdge(g,0,1,1);
  insertBEdge(g,1,2,1);
  insertBEdge(g,2,0,1);
  assert(hasCycle(g) == 1);
  dropGraph(g);

  g = newGraph(6);
  insertBEdge(g,0,2,1);
  insertBEdge(g,2,1,1);
  insertBEdge(g,3,4,1);
  insertBEdge(g,3,5,1);
  insertBEdge(g,4,5,1);
  assert(hasCycle(g) == 1);
  dropGraph(g);

  printf("Passed all tests for hasCycle!\n");
}

void testComponents() {
  Graph g;
  int* res;

  g = newGraph(3);
  insertBEdge(g,0,1,1);
  insertBEdge(g,0,2,1);
  insertBEdge(g,1,2,1);
  res = components(g);
  assert(res[0] == res[1]);
  assert(res[1] == res[2]);
  dropGraph(g);

  g = newGraph(7);
  insertBEdge(g,0,1,1);
  insertBEdge(g,0,2,1);
  insertBEdge(g,1,2,1);
  insertBEdge(g,3,4,1);
  insertBEdge(g,5,6,1);
  res = components(g);
  assert(res[0] == res[1]);
  assert(res[1] == res[2]);
  assert(res[3] == res[4]);
  assert(res[5] == res[6]);
  dropGraph(g);

  printf("Passed all tests for components!!\n");
}

int main() {
  testCycle();
  testWithin();
  testBipartition();
  testComponents();
  printf("Congrats passed all autotests, make sure to write some of your own ones as well!\n");
}
