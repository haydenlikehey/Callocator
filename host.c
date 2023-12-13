#include "allocator.h"

int main(void) {

  //this union is holding the integer pointer
  union allocateReturn intpointer = allocateDebug(UINT, 8);
  
  intpointer.uintptr[0] = 10;
  intpointer.uintptr[3] = 999;
  intpointer.uintptr[4] = 334;
  intpointer.uintptr[7] = 90;

  for (int i = 0; i < 8; i++) {
    printf("%i\n", intpointer.uintptr[i]);
  }



}