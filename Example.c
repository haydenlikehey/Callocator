#include "allocator.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

/*
this union is holding the integer pointer
Need to think about extending this to a struct that tracks how much memory
is allocated. I think that might be a little useful, but I think I've got
interpretive brain from too much R
*/
  union allocated intpointer = allocatorUnion(UINT, 8);
  unsigned int* trial = intpointer.uintptr; //I feel like you shouldn't do this

  //struct memory* structOne;
  // (*structOne).size = 10; Don't do this. You can't write to memeory that doesn't exist
  //structOne = allocatorStruct(SINT, (*structOne).size); //Leads to this mess

  //struct memory* structTwo;
  //structTwo->size = 20; It doesn't work like this either
  //structTwo = allocatorStruct(SINT, structTwo->size);

  struct memory* structThree = allocator(SINT, 30); //Or do it this way and smile
  
  //This works. Just a convoluted way to access memory though. Not sure if it's
  //useful.
  //If you're doing wacky stuff like the Quake fast inverse square root, maybe
  *intpointer.uintptr = 10;
  *(intpointer.uintptr + 2) = 999;
  intpointer.uintptr[4] = 334;
  intpointer.uintptr[7] = 90;

  //Wow, this works too! Wow!
  *(trial + 5) = 9000;

  //This prints junk data for the memory not initiated. Be cautious
  //Might be an initializer too.
  for (int i = 0; i < 8; i++) {
    printf("%i\n", intpointer.uintptr[i]);
  }

  printf("struct 3 size: %llu\n", (*structThree).size);

  //Be a good C citizen!
  free(intpointer.uintptr);
  //free(structOne);
  //free(structTwo);
  freememory(structThree, SINT); //This doesn't free the submemory

  return 0;

}