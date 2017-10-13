#include "Tests.h"
#include "BST.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

// Test Methods
void findValTest1();
void findValTest2();
void findValTest3();

// 'main' method
void findValTests() {
  void (*tests[])(void) = {
    findValTest1,
    findValTest2,
    findValTest3,
  };

  printf("Running findValTests\n");
  unsigned long i = 0;
  for (i = 0; i < sizeof(tests)/sizeof(void*); ++i) {
    printf("Starting findValTest %lu\n", i);
    tests[i]();
    printf("Congrats! Passed findValTest %lu\n\n", i);
  }
  printf("Passed findValTests!\n");
}

void findValTest1() {
  Tree t = createTree();
  assert(findValue(t, 0) == 0);
  assert(findValue(t, -1) == 0);
  assert(findValue(t, 1) == 0);
}

void findValTest2() {
  Tree t = createTree();
  int vals[] = { 1, 2, 3, 4, 5 };

  t = buildTree(t, vals, sizeof(vals) / sizeof(int), insert);

  assert(findValue(t, 0) == 0);
  assert(findValue(t, 1) == 1);
  assert(findValue(t, 2) == 1);
  assert(findValue(t, 3) == 1);
  assert(findValue(t, 4) == 1);
  assert(findValue(t, 5) == 1);
  assert(findValue(t, 6) == 0);
}

void findValTest3() {
  Tree t = createTree();
  int vals[] = { 4, 2, 1, 3, 6, 5, 7 };

  t = buildTree(t, vals, sizeof(vals) / sizeof(int), insert);

  assert(findValue(t, -1) == 0);
  assert(findValue(t, 1) == 1);
  assert(findValue(t, 4) == 1);
  assert(findValue(t, 3) == 1);
  assert(findValue(t, 7) == 1);
  assert(findValue(t, 6) == 1);
  assert(findValue(t, 6) == 1);
}
