#include "Tests.h"
#include "BST.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

int doubleANumber(int number) {
    return number * 2;
}

int halveANumber(int number) {
    return number / 2;
}

// 'main' method
void mapTests() {
    Tree t = createTree();
    int vals[] = { 1, 2, 3, 4, 5 };
    t = buildTree(t, vals, sizeof(vals) / sizeof(int), insert);
    int (*doublefp)(int) = &doubleANumber;
    map(t, doublefp);
    assert(findValue(t, 2) == 1);
    assert(findValue(t, 4) == 1);
    assert(findValue(t, 6) == 1);
    assert(findValue(t, 8) == 1);
    assert(findValue(t, 10) == 1);
    assert(findValue(t, 1) == 0);
    assert(findValue(t, 3) == 0);
    assert(findValue(t, 5) == 0);

    printf("Passed mapTests!\n");
}

void mapTest1() {
  //Tree t = createTree();
  //assert(findValue(t, 0) == 0);
  //assert(findValue(t, -1) == 0);
  //assert(findValue(t, 1) == 0);
}

void mapTest2() {
/*
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
  */
}

void mapTest3() {
/*
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
  */
}
