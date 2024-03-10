#include <stdbool.h>
#include <stdint.h>

//Idk what the biggest reasonable amount of memory to allocate is
//So here's a MB for your troubles. Configure as you see fit.
#define MAX_ALLOC 1048576


enum MemType {
  S8,
  U8,
  S16,
  U16,
  S32,
  U32,
  S64,
  U64,
  FLOAT,
  DOUBLE,
  STRING,
  BOOL,
  FAIL
};

union allocated {
  int8_t* sint8ptr;
  uint8_t* uint8ptr;
  int16_t* sint16ptr;
  uint16_t* uint16ptr;
  int32_t* sint32ptr;
  uint32_t* uint32ptr;
  int64_t* sint64ptr;
  uint64_t* uint64ptr;
  float* fptr;
  double* dptr;
  char* string;
  bool* bptr;
  char ehandle;
};

struct memory {
  uint64_t size;
  union allocated type;
};


//Is it overengineered for still returning a void*? Maybe. But this way hopefully it will not
//be abused and will be implementation independent.
union allocated allocatorUnion(enum MemType t, unsigned long long size);
struct memory* allocator(enum MemType t, unsigned long long elements);
unsigned long long byteSize(enum MemType t, unsigned long long elements);
void freememory(struct memory* toBeFreed, enum MemType t);