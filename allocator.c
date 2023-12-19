#include "allocator.h"
#include <stdio.h>
#include <stdlib.h>

union allocated allocatorDebug(enum Type t, int size) {

  if (size > MAX_ALLOC) {
      puts("Nahhhh, mate, that's too much mem. Allocation failed\n");
      t = FAIL;
  }
//Let's think about returning a union of the specific yunyun type instead of void*
  union allocated yunyun;
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
  case STRING:
    printf("Allocated %llu bytes.\n", size * sizeof(char));
    yunyun.string = malloc(size * sizeof(char));
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

struct memory* allocatorStruct(enum Type t, unsigned long long elements) {

  struct memory* m;
  m->size = elements;

  //create a new function that returns size based on Type
  //We can use that to make a hard MB limit or whatever
  if (byteSize(t, elements) > MAX_ALLOC) {
      puts("Nahhhh, mate, that's too much mem. Allocation failed\n");
      t = FAIL;
  }

//
//Next step: Make an initiator so junk data isn't made.
//
switch (t) {
  case SHORT:
    printf("Allocated %llu bytes.\n", elements * sizeof(short));
    m->type.shortptr = malloc(elements * sizeof(short));
    return m;
    break;
  case UINT:
    printf("Allocated %llu bytes.\n", elements * sizeof(unsigned int));
    m->type.uintptr = malloc(elements * sizeof(unsigned int));
    return m;
    break;
  case SINT:
    printf("Allocated %llu bytes.\n", elements * sizeof(signed int));
    m->type.sintptr = malloc(elements * sizeof(signed int));
    return m;
    break;
  case SLLONG:
    printf("Allocated %llu bytes.\n", elements * sizeof(signed long long));
    m->type.sllptr = malloc(elements * sizeof(signed long long));
    return m;
    break;
  case ULLONG:
    printf("Allocated %llu bytes.\n", elements * sizeof(unsigned long long));
    m->type.ullptr = malloc(elements * sizeof(unsigned long long));
    return m;
    break;
  case FLOAT:
    printf("Allocated %llu bytes.\n", elements * sizeof(float));
    m->type.fptr = malloc(elements * sizeof(float));
    return m;
    break;
  case DOUBLE:
    printf("Allocated %llu bytes.\n", elements * sizeof(double));
    m->type.dptr = malloc(elements * sizeof(double));
    return m;
    break;
  case STRING:
    printf("Allocated %llu bytes.\n", elements * sizeof(char));
    m->type.string = malloc(elements * sizeof(char));
    return m;
    break;
  case BOOL:
    printf("Allocated %llu bytes.\n", elements * sizeof(bool));
    m->type.bptr = malloc(elements * sizeof(bool));
    return m;
  case FAIL:
    exit(8254); //I feel like a hard exit is a little harsh... but it is C!
    return m;
    break;
  default:
    puts("You tried to allocate a type that doesn't exist\n");
    m->type.ehandle = 'F';
    return m;
    break;
  }

  m->type.ehandle = 'L'; //Third error handle... It's bullet proof but it could use another
  return m;             //function just be safe lol
  

}

unsigned long long byteSize(enum Type t, unsigned long long elements) {

  switch (t) {
    case SHORT:
      return elements * sizeof(short);
      break;
    case UINT:
      return elements * sizeof(unsigned int);
      break;
    case SINT:
      return elements * sizeof(signed int);
      break;
    case SLLONG:
      return elements * sizeof(signed long long);
      break;
    case ULLONG:
      return elements * sizeof(unsigned long long);
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
      exit(8254);
      break;
    }

}