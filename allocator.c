#include "allocator.h"
#include <stdio.h>
#include <stdlib.h>

union allocateReturn allocateDebug(enum Type t, int size) {

  if (size > MAX_ALLOC) {
      puts("Nahhhh, mate, that's too much mem. Allocation failed\n");
      t = FAIL;
  }
//Let's think about returning a union of the specific yunyun type instead of void*
  union allocateReturn yunyun;
  yunyun.shortptr = NULL;

switch (t) {
  case SHORT:
    printf("Allocated %llu bytes.\n", size * sizeof(short));
    yunyun.shortptr = malloc(size * sizeof(short));
    return yunyun;
    break;
  case UINT:
    printf("Allocated %llu bytes.\n", size * sizeof(unsigned int));
    yunyun.uintptr = malloc(size * sizeof(unsigned int));
    return yunyun;
    break;
  case SINT:
    printf("Allocated %llu bytes.\n", size * sizeof(signed int));
    yunyun.sintptr = malloc(size * sizeof(signed int));
    return yunyun;
    break;
  case SLLONG:
    printf("Allocated %llu bytes.\n", size * sizeof(signed long long));
    yunyun.sllptr = malloc(size * sizeof(signed long long));
    return yunyun;
    break;
  case ULLONG:
    printf("Allocated %llu bytes.\n", size * sizeof(unsigned long long));
    yunyun.ullptr = malloc(size * sizeof(unsigned long long));
    return yunyun;
    break;
  case FLOAT:
    printf("Allocated %llu bytes.\n", size * sizeof(float));
    yunyun.fptr = malloc(size * sizeof(float));
    return yunyun;
    break;
  case DOUBLE:
    printf("Allocated %llu bytes.\n", size * sizeof(double));
    yunyun.dptr = malloc(size * sizeof(double));
    return yunyun;
    break;
  case CHAR:
    printf("Allocated %llu bytes.\n", size * sizeof(char));
    yunyun.cptr = malloc(size * sizeof(char));
    return yunyun;
    break;
  case BOOL:
    printf("Allocated %llu bytes.\n", size * sizeof(bool));
    yunyun.bptr = malloc(size * sizeof(bool));
    return yunyun;
  case FAIL:
    exit(8254);
    return yunyun;
    break;
  default:
    puts("You tried to allocate a type that doesn't exist\n");
    break;
  }
  yunyun.ehandle = 'L';
  return yunyun;

}