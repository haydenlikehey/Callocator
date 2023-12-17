#include "allocator.h"

int main(void) {

  //this union is holding the integer pointer
  //Need to think about extending this to a struct that tracks how much memory is allocated.
  union allocateReturn intpointer = allocateDebug(UINT, 8);
  
  //This works. Just a convoluted way to access memory though. Not sure if it's useful.
  //If you're doing wacky stuff like the Quake fast inverse square root 
  *intpointer.uintptr = 10;
  *(intpointer.uintptr + 2) = 999;
  intpointer.uintptr[4] = 334;
  intpointer.uintptr[7] = 90;

  //This prints junk data for the memory not initiated. Be cautious
  for (int i = 0; i < 8; i++) {
    printf("%i\n", intpointer.uintptr[i]);
  }

  //Be a good C citizen!
  free(intpointer.uintptr);

}