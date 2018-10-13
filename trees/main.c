#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Tests.h"

void printHelp() {
  printf("\
Some cool tree functions\n\
To run tests, go ./solution XXX where XXX is:\n\
  --all - run all tests\n\
  0     - findValue\n\
  1     - isBST\n\
  2     - getKthSmallest\n\
  3     - lowestCommonAnc\n\
  4     - successor\n");
}

int main(int argc, char* argv[]) {
  if (argc <= 1) {
    printHelp();
    return 1;
  }

  void (*tests[])(void) = {
    findValTests,
    isBSTTests,
    kthSmallestTests,
    lowestCommonAncTests,
    successorTests
  };

  unsigned long testNum = 0;
  if (strcmp(argv[1], "--all") == 0) {
    for (; testNum < sizeof(tests)/(sizeof(void*)); ++testNum) {
      tests[testNum]();
    }
  } else {
    testNum = atoi(argv[1]);
    if (testNum >= sizeof(tests)/(sizeof(void*))) {
      printHelp();
      return 1;
    }
    tests[testNum]();
  }

  printf("You passed all the tests. Good for you.\n");
  return 0;
}
