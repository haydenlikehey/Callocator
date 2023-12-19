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
  STRING,
  BOOL,
  FAIL,
  FREE
};

union allocated {
  short* shortptr;
  unsigned int* uintptr;
  signed int* sintptr;
  signed long long* sllptr;
  unsigned long long* ullptr;
  float* fptr;
  double* dptr;
  char* string;
  bool* bptr;
  char ehandle;
};

struct memory {
  unsigned long long size;
  union allocated type;
};


//Is it overengineered for still returning a void*? Maybe. But this way hopefully it will not
//be abused and will be implementation independent.
union allocated allocatorDebug(enum Type t, int size);
struct memory* allocatorStruct(enum Type t, unsigned long long elements);
unsigned long long byteSize(enum Type t, unsigned long long elements);