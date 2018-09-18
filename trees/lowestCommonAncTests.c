#include "Tests.h"
#include "BST.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

// Test Methods
void lowestCommonAncTest1();
void lowestCommonAncTest2();

// 'main' method
void lowestCommonAncTests() {
  void (*tests[])(void) = {
    lowestCommonAncTest1,
    lowestCommonAncTest2,
  };

  printf("Running lowestCommonAncTests\n");
  unsigned long i = 0;
  for (i = 0; i < sizeof(tests)/sizeof(void*); ++i) {
    printf("Starting lowestCommonAncTest %lu\n", i);
    tests[i]();
    printf("Congrats! Passed lowestCommonAncTest %lu\n\n", i);
  }
  printf("Passed lowestCommonAncTests!\n");
}

void lowestCommonAncTest1() {
  Tree t = createTree();
  assert(lowestCommonAnc(t, 0, 0) == NULL);
}

void lowestCommonAncTest2() {
  Tree t = createTree();
  int vals[] = { 4, 2, 7, 1, 3, 6, 0 };
  t = buildTree(t, vals, sizeof(vals) / sizeof(int), insert);

  assert(getRootVal(lowestCommonAnc(t, 2, 7)) == 4);
  assert(getRootVal(lowestCommonAnc(t, 0, 3)) == 2);
  assert(getRootVal(lowestCommonAnc(t, 3, 0)) == 2);
  assert(getRootVal(lowestCommonAnc(t, 0, 6)) == 4);
  assert(getRootVal(lowestCommonAnc(t, 6, 0)) == 4);
}
