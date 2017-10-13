#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Stack.h"
#include "Queue.h"

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
  assert(n == 5);
  assert(res[0]==1);
  for (i=0,j=1; i<6; i++) {
    if (i==1) continue;
    assert( res[j++] == i);
  }
  free(res);

  res = within(g,5,1,&n);
  assert(n == 2);
  assert(res[0] == 5);
  assert(res[1] == 5);

  dropGraph(g);
  printf("Passed tests for within!\n");
}

void testBipartition() {


}

void testCycle() {

}

void testComponents() {

}

int main() {
  testWithin();
  testBipartition();
  testCycle();
  testComponents();
}
