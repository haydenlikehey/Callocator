#include "allocator.h" //stdint.h is declared in here
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union allocated allocatorUnion(enum MemType declaredType, uint64_t size) {

  if (size > MAX_ALLOC) {
      declaredType = FAIL;
  }
//Let's think about returning a union of the specific yunyun type instead of void*
  union allocated yunyun;
  yunyun.uint16ptr = NULL;
  int errorCount = 0;

switch (declaredType) {
  case U16:
    do {
      yunyun.uint16ptr = malloc(size * sizeof(uint16_t));
      if (yunyun.uint16ptr == NULL) {
        errorCount++;
      }
      if (errorCount > 2) {
        puts("Memory allocation has failed too many times -- aborting.");
        exit(12);
      }
    } while (yunyun.uint16ptr == NULL);
    memset(yunyun.uint16ptr, 0, (size * sizeof(uint16_t)));
    printf("Allocated %llu bytes.\n", size * sizeof(uint16_t));
    return yunyun;
    break;
  case U32:
    printf("Allocated %llu bytes.\n", size * sizeof(uint32_t));
    yunyun.uint32ptr = malloc(size * sizeof(uint32_t));
    memset(yunyun.uint32ptr, 0, (size * sizeof(uint32_t)));
    return yunyun;
    break;
  case S32:
    printf("Allocated %llu bytes.\n", size * sizeof(int32_t));
    yunyun.sint32ptr = malloc(size * sizeof(int32_t));
    memset(yunyun.sint32ptr, 0, (size * sizeof(int32_t)));
    return yunyun;
    break;
  case S64:
    printf("Allocated %llu bytes.\n", size * sizeof(int64_t));
    yunyun.sint64ptr = malloc(size * sizeof(int64_t));
    memset(yunyun.sint64ptr, 0, (size * sizeof(int64_t)));
    return yunyun;
    break;
  case U64:
    printf("Allocated %llu bytes.\n", size * sizeof(uint64_t));
    yunyun.uint64ptr = malloc(size * sizeof(uint64_t));
    memset(yunyun.uint64ptr, 0, (size * sizeof(uint64_t)));
    return yunyun;
    break;
  case FLOAT:
    printf("Allocated %llu bytes.\n", size * sizeof(float));
    yunyun.fptr = malloc(size * sizeof(float));
    memset(yunyun.fptr, 0, (size * sizeof(float)));
    return yunyun;
    break;
  case DOUBLE:
    printf("Allocated %llu bytes.\n", size * sizeof(double));
    yunyun.dptr = malloc(size * sizeof(double));
    memset(yunyun.dptr, 0, (size * sizeof(double)));
    return yunyun;
    break;
  case STRING:
    printf("Allocated %llu bytes.\n", size * sizeof(char));
    yunyun.string = malloc(size * sizeof(char));
    memset(yunyun.string, '\0', (size * sizeof(char)) - 1); //Verify how dynamic strings work
    return yunyun;
    break;
  case BOOL:
    printf("Allocated %llu bytes.\n", size * sizeof(bool));
    yunyun.bptr = malloc(size * sizeof(bool));
    memset(yunyun.bptr, 0, (size * sizeof(bool)));
    return yunyun;
  case FAIL:
    puts("An attempt was made to allocate more memory than defined by the author...");
    puts("An 'L' has been returned.");
    yunyun.ehandle = 'L';
    return yunyun;
    break;
  default:
    puts("You tried to allocate a type that doesn't exist\n");
    break;
  }
  yunyun.ehandle = 'L';
  return yunyun;

}

struct memory* allocator(enum MemType declaredType, uint64_t elements) {

  struct memory* managedMemory = malloc(sizeof(struct memory));
  managedMemory->size = elements;

  if (byteSize(declaredType, elements) > MAX_ALLOC) {
      puts("Nahhhh, mate, that's too much mem. Allocation failed\n");
      declaredType = FAIL;
  }

//
//Next step: Make an initiator so junk data isn't made.
//
  switch (declaredType) {
     case U8:
      printf("Allocated %llu bytes.\n", elements * sizeof(uint8_t));
      managedMemory->type.uint8ptr = malloc(elements * sizeof(uint8_t));
      memset(managedMemory->type.uint8ptr, 0, (elements * sizeof(uint8_t)));
      return managedMemory;
      break;
    case S8:
      printf("Allocated %llu bytes.\n", elements * sizeof(int8_t));
      managedMemory->type.sint8ptr = malloc(elements * sizeof(int8_t));
      memset(managedMemory->type.sint8ptr, 0, (elements * sizeof(int8_t)));
      return managedMemory;
      break;
    case S16:
      printf("Allocated %llu bytes.\n", elements * sizeof(int16_t));
      managedMemory->type.sint16ptr = malloc(elements * sizeof(int16_t));
      memset(managedMemory->type.sint16ptr, 0, (elements * sizeof(int16_t)));
      return managedMemory;
      break;
    case U16:
      printf("Allocated %llu bytes.\n", elements * sizeof(uint16_t));
      managedMemory->type.uint16ptr = malloc(elements * sizeof(uint16_t));
      memset(managedMemory->type.uint16ptr, 0, (elements * sizeof(uint16_t)));
      return managedMemory;
      break;
    case U32:
      printf("Allocated %llu bytes.\n", elements * sizeof(uint32_t));
      managedMemory->type.uint32ptr = malloc(elements * sizeof(uint32_t));
      memset(managedMemory->type.uint32ptr, 0, (elements * sizeof(uint32_t)));
      return managedMemory;
      break;
    case S32:
      printf("Allocated %llu bytes.\n", elements * sizeof(int32_t));
      managedMemory->type.sint32ptr = malloc(elements * sizeof(int32_t));
      memset(managedMemory->type.sint32ptr, 0, (elements * sizeof(int32_t)));
      return managedMemory;
      break;
    case S64:
      printf("Allocated %llu bytes.\n", elements * sizeof(int64_t));
      managedMemory->type.sint64ptr = malloc(elements * sizeof(int64_t));
      memset(managedMemory->type.sint64ptr, 0, (elements * sizeof(int64_t)));
      return managedMemory;
      break;
    case U64:
      printf("Allocated %llu bytes.\n", elements * sizeof(uint64_t));
      managedMemory->type.uint64ptr = malloc(elements * sizeof(uint64_t));
      memset(managedMemory->type.uint64ptr, 0, (elements * sizeof(uint64_t)));
      return managedMemory;
      break;
    case FLOAT:
      printf("Allocated %llu bytes.\n", elements * sizeof(float));
      managedMemory->type.fptr = malloc(elements * sizeof(float));
      memset(managedMemory->type.fptr, 0, (elements * sizeof(float)));
      return managedMemory;
      break;
    case DOUBLE:
      printf("Allocated %llu bytes.\n", elements * sizeof(double));
      managedMemory->type.dptr = malloc(elements * sizeof(double));
      memset(managedMemory->type.dptr, 0, (elements * sizeof(double)));
      return managedMemory;
      break;
    case STRING:
      printf("Allocated %llu bytes.\n", elements * sizeof(char));
      managedMemory->type.string = malloc(elements * sizeof(char));
      memset(managedMemory->type.string, '\0', (elements * sizeof(char)));
      return managedMemory;
      break;
    case BOOL:
      printf("Allocated %llu bytes.\n", elements * sizeof(bool));
      managedMemory->type.bptr = malloc(elements * sizeof(bool));
      memset(managedMemory->type.bptr, 0, (elements * sizeof(bool)));
      return managedMemory;
    case FAIL:
      exit(8254); //I feel like a hard exit is a little harsh... but it is C!
      return managedMemory;
      break;
    default:
      puts("You tried to allocate a type that doesn't exist\n");
      managedMemory->type.ehandle = 'F';
      return managedMemory;
      break;
  }

  managedMemory->type.ehandle = 'L'; //Third error handle... It's buint64et proof but it could use another
  return managedMemory;             //function just be safe lol

}

void freememory(struct memory* toBeFreed, enum MemType declaredType) {

  switch (declaredType) {
    case U8:
      free(toBeFreed->type.uint8ptr);
      break;
    case S8:
      free(toBeFreed->type.sint8ptr);
      break;
    case U16:
      free(toBeFreed->type.uint16ptr);
      break;
    case S16:
      free(toBeFreed->type.sint16ptr);
      break;
    case U32:
      free(toBeFreed->type.uint32ptr);
      break;
    case S32:
      free(toBeFreed->type.sint32ptr);
      break;
    case S64:
      free(toBeFreed->type.sint64ptr);
      break;
    case U64:
      free(toBeFreed->type.uint64ptr);
      break;
    case FLOAT:
      free(toBeFreed->type.fptr);
      break;
    case DOUBLE:
      free(toBeFreed->type.dptr);
      break;
    case STRING:
      free(toBeFreed->type.string);
      break;
    case BOOL:
      free(toBeFreed->type.bptr);
    case FAIL:
      /*This is meant to allow passthrough for failed allocations returned by
        allocatorStruct() or allocatorUnion()
        Since ehandle has mem allocated for it as part of the union, it can be
        freed with the structure.*/
      break;
    default:
      puts("No type to Free\n");
      return;

  }
  free(toBeFreed);
  return;

}

uint64_t byteSize(enum MemType declaredType, uint64_t elements) {

  switch (declaredType) {
    case U8:
      return elements * sizeof(uint8_t);
      break;
    case S8:
      return elements * sizeof(int8_t);
      break;
    case U16:
      return elements * sizeof(uint16_t);
      break;
    case S16:
      return elements * sizeof(int16_t);
      break;
    case U32:
      return elements * sizeof(uint32_t);
      break;
    case S32:
      return elements * sizeof(int32_t);
      break;
    case S64:
      return elements * sizeof(int64_t);
      break;
    case U64:
      return elements * sizeof(uint64_t);
      break;
    case FLOAT:
      return elements * sizeof(float);
      break;
    case DOUBLE:
      return elements * sizeof(double);
      break;
    case STRING:
      return elements * sizeof(char);
      break;
    case BOOL:
      return elements * sizeof(bool);
      break;
    default:
      exit(3); //Memory access violation?
      break;
    }

}