#include "BST.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void  test1();
void  test2();
void  test3();
void  test4();
void  test5();

void successorTests() {


  void (*tests[])(void) = {
    test1,
    test2,
    test3,
    test4,
    test5,
  };

  printf("Running Tests\n");
  unsigned long i = 0;
  for (i = 0; i < sizeof(tests)/sizeof(void*); ++i) {
    printf("Starting Test %lu\n", i);
    tests[i]();
    printf("Congrats! Passed Test %lu\n\n",     i);
  }
  printf("Passed Tests!\n");
}

void test1() {
  Tree t = createTree();
  t = insert(t, 5);
  t = insert(t, 3);
  assert(successor(t,find(t,3)) == t);
}

void test2() {
  Tree t = createTree();
  t = insert(t, 5);
  t = insert(t, 3);
  t = insert(t, 10);
  t = insert(t, 6);
  t = insert(t, 9);
  t = insert(t, 1);
  
  assert(getValue(successor(t, find(t,6))) == 9);
}

void test3() {
  Tree t = createTree();

  t = insert(t, 5);
  assert(successor(t, find(t,5)) == NULL);
}

void test4() {
  Tree t = createTree();
  t = insert(t, 5);
  t = insert(t, 3);
  t = insert(t, 10);
  assert(getValue(successor(t, find(t,5))) == 10);
}

void test5() {
  Tree t = createTree();
  t = insert(t, 5);
  t = insert(t, 3);
  t = insert(t, 10);
  t = insert(t, 6);
  t = insert(t, 9);
  assert(getValue(successor(t, find(t, 5))) == 6);
  assert(getValue(successor(t, find(t, 6))) == 9);
}


