#include "Tests.h"
#include "BST.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

// Test Methods
void testValidBST(int);
void testInValidBST(int);

// 'main' method
void isBSTTests() {

  printf("Running isBSTTests\n");
  unsigned long i = 0;
  for (i = 0; i < 8; i++) { 
    printf("Starting isBSTTest %lu\n", i);
    i%2 ? testInValidBST(i) : testValidBST(i);
    printf("Congrats! Passed isBSTTest %lu\n\n", i);
  }
  printf("Passed isBSTTests!\n");
}

void testValidBST(int c) {
  Tree t = buildInvalidTree(c);
  assert(isBST(t) == 1);
}

void testInValidBST(int c) {
  assert(isBST(buildInvalidTree(c)) == 0);
}
