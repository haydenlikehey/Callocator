#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ALLOC 1000000


enum Type {
  SHORT,
  SINT,
  UINT,
  SLLONG,
  ULLONG,
  FLOAT,
  DOUBLE,
  CHAR,
  BOOL,
  FAIL
};

//Think about putting the union for the proposed idea in the other file here

union allocateReturn {
  short* shortptr;
  unsigned int* uintptr;
  signed int* sintptr;
  signed long long* sllptr;
  unsigned long long* ullptr;
  float* fptr;
  double* dptr;
  char* cptr;
  bool* bptr;
  char ehandle;
};


//Is it overengineered for still returning a void*? Maybe. But this way hopefully it will not
//be abused and will be implementation independent.
union allocateReturn allocateDebug(enum Type t, int size);