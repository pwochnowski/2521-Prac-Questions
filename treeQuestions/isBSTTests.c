#include "Tests.h"
#include "BST.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

// If for some reason these tests sometimes pass/sometimes fail you
// it's because we use a yolo method of inserting, it may somehow
// randomly insert it into the correct position even though it's
// random. Just #hope

// Test Methods
void isBSTTest1();
void isBSTTest2();
void isBSTTest3();
void isBSTTest4();
void isBSTTest5();

// 'main' method
void isBSTTests() {
  void (*tests[])(void) = {
    isBSTTest1,
    isBSTTest2,
    isBSTTest3,
    isBSTTest4,
    isBSTTest5
  };

  printf("Running isBSTTests\n");
  unsigned long i = 0;
  for (i = 0; i < sizeof(tests)/sizeof(void*); ++i) {
    printf("Starting isBSTTest %lu\n", i);
    tests[i]();
    printf("Congrats! Passed isBSTTest %lu\n\n", i);
  }
  printf("Passed isBSTTests!\n");
}

void isBSTTest1() {
  Tree t = createTree();
  assert(isBST(t) == 1);
}

void isBSTTest2() {
  Tree t = createTree();
  int vals[] = { 4, 2, 1, 3, 6, 5, 7 };

  t = buildTree(t, vals, sizeof(vals) / sizeof(int), insert);

  assert(isBST(t) == 1);
}

void isBSTTest3() {
  Tree t = createTree();
  int vals[] = { 4, 2, 1, 3, 6, 5, 7 };

  t = buildTree(t, vals, sizeof(vals) / sizeof(int), randInsert);

  assert(isBST(t) == 0);
}

void isBSTTest4() {
  Tree t = createTree();
  int vals[] = { 4, 2, 1, 3, 6, 5, 7 };

  t = buildTree(t, vals, sizeof(vals) / sizeof(int), insert);
  assert(isBST(t) == 1);

  t = randInsert(t, 100);
  assert(isBST(t) == 0);
}

void isBSTTest5() {
  Tree t = createTree();
  assert(isBST(t) == 1);

  t = randInsert(t, 5);
  assert(isBST(t) == 1);

  t = insert(t, 6);
  assert(isBST(t) == 1);

  t = insert(t, 9);
  assert(isBST(t) == 1);

  t = insert(t, 7);
  assert(isBST(t) == 1);

  t = randInsert(t, 8);
  assert(isBST(t) == 0);
}
