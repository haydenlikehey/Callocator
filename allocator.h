#include <stdbool.h>

//Idk what the biggest reasonable amount of memory to allocate is
//So here's a MB for your troubles. Configure as you see fit.
#define MAX_ALLOC 1048576


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
  FAIL,
  FREE
};

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

struct memory {
  unsigned long long size;
  enum Type type; //does this need to be here?
  union allocated;
};


//Is it overengineered for still returning a void*? Maybe. But this way hopefully it will not
//be abused and will be implementation independent.
union allocateReturn allocatorDebug(enum Type t, int size);
struct memory allocatorStruct(struct memory m);