#include "util.h"

int fun_sort(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}
