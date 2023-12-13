#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ALLOC 1000000


enum Type {
  SHORT,
  SINT,
  UINT,
  S32,
  U32,
  S64,
  U64,
  SLLONG,
  ULLONG,
  FLOAT,
  DOUBLE,
  CHAR,
  BOOL,
  FAIL
};

//Think about putting the union for the proposed idea in the other file here

//Pass size using sizeof operator
//Is it overengineered for still returning a void*? Maybe. But this way hopefully it will not
//be abused and will be implementation independent.
void* allocateDebug(enum Type t, int size);
