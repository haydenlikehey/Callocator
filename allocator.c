#include "allocator.h"

void* allocateDebug(enum Type t, int size) {

  if (size > MAX_ALLOC) {
      puts("Nahhhh, mate, that's too much mem. Allocation failed\n");
      t = FAIL;
  }
//Let's think about returning a union of the specific pointer type instead of void*

switch (t) {
  case SHORT:
    printf("Allocated %llu bytes.\n", size * sizeof(short));
    return malloc(size * sizeof(short));
    break;
  case UINT:
  case U32:
    printf("Allocated %llu bytes.\n", size * sizeof(unsigned int));
    return malloc(size * sizeof(unsigned int));
    break;
  case S32:
  case SINT:
    printf("Allocated %llu bytes.\n", size * sizeof(signed int));
    return malloc(size * sizeof(signed int));
    break;
  case S64:
  case SLLONG:
    printf("Allocated %llu bytes.\n", size * sizeof(signed long long));
    return malloc(size * sizeof(signed long long));
    break;
  case U64:
  case ULLONG:
    printf("Allocated %llu bytes.\n", size * sizeof(unsigned long long));
    return malloc(size * sizeof(unsigned long long));
    break;
  case FLOAT:
    printf("Allocated %llu bytes.\n", size * sizeof(float));
    return malloc(size * sizeof(float));
    break;
  case DOUBLE:
    printf("Allocated %llu bytes.\n", size * sizeof(double));
    return malloc(size * sizeof(double));
    break;
  case CHAR:
    printf("Allocated %llu bytes.\n", size * sizeof(char));
    return malloc(size * sizeof(char));
    break;
  case BOOL:
    printf("Allocated %llu bytes.\n", size * sizeof(bool));
    return malloc(size * sizeof(bool));
  case FAIL:
    break;
  default:
    puts("You tried to allocate a type that doesn't exist\n");
    break;
  }

  return NULL;

}