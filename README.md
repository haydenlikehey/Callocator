# Callocator

I got this bright idea out of the blue: What if I made C heap allocation an easier process? Well, I hadn't coded anything in a while so I thought "Why the hell not?" Turns out, allocating memory isn't actually the hard part. It's keeping track of pointers in a big ass project, right? Well, it can help with that. I even learned a thing or two about enums, unions, structs, and struct pointers that I didn't know before, so I'm happy with that.

## Is this easier than just using malloc?

At declaration? I think so. Using it to change state? Good luck! It's clearer than malloc in its use imo, allows you to internally check the size of the memory you've allocated for safety, and ensures in some way that you remember the type of memory you're manipulating through the use of the pointer type system. The tradeoff? It's very "wordy".

## How to use?

### enum Type

enum Type is an enumeration meant to represent the types available for allocating a pointer. These are SHORT (short), SINT (signed int), UINT (unsigned int), SLLONG (signed long long), ULLONG (unsigned long long), FLOAT (float), DOUBLE (double), STRING (char), and BOOL (bool). To more "types" are provided for internal error handling and future features.

### Union Implementation

The union "allocated" is a union that holds a pointer of any of the types I could think of or a character that signals that allocation has failed.

The function allocatorUnion() returns the type union allocated and accepts the parameters enum Type and then an unsigned long long representing the number of elements you wish to allocate with a default limit of 1 MB declared in the preprocessor of allocator.h. The function then checks to make sure you're not allocating too much memory compared to MAX_ALLOC, uses malloc() to assign you the memory requested based off of size you passed the function, and returns the union which is occupied by the pointer type of the requested memory. If too much memory is requested, a message is printed and the program exits with code 8254. If you pass the function a Type that does not exist, the function returns the character 'L' in the union instead and a message indicating the failure is printed.

### Structure Implementation

#### Allocation

For convenience and an attempt at safety, the structure "memory" contains an unsigned long long called "size" and a union allocated called "type".

The function allocatorStruct() accepts the same parameters as allocator union: an enum Type and an unsigned long long value and begins with a size check. However, this function returns a struct memory pointer and you should set a struct memory pointer to be assigned the output of the function. The function first creates a struct memory pointer to return and allocates memory for it. Next, size is allocated and set to the number of elements in the heap. Following this memory is allocated for the data type requested, assigned to the pointer within union allocated that is within struct memory, then returned.

#### Deallocation

Call freememory() with parameters struct memory pointer and enum Type.