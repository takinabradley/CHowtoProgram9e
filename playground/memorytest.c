/* 
  This code attemps to dynamically allocate a chunk of memory with `malloc`, 
  then manually manipulates and stores multiple values in that memory.
*/
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
  uint8_t size;
  uint8_t * address;
  bool freed;
} CustomMemory;

typedef struct {
  uint8_t size;
  uint8_t start;
} DataInfo;

CustomMemory allocateCustomMemory(uint8_t size) {
  // dynamically allocates a chunk of memory and packages it in a struct.
  CustomMemory theCustomMemory = {size, malloc(size), false};
  return theCustomMemory;
}

DataInfo assignToCustomMemory(CustomMemory memory, uint8_t index, uint8_t sizeInBytes, void * data) {
  // assigns a value somewhere in an CustomMemory object for use later.

  if(
    index > memory.size - 1 ||                      // the index is out of bounds
    index < 0 || 
    index + (sizeInBytes - 1) > memory.size - 1 ||  // the amount of bytes will exceed bound from index
    sizeInBytes < 0                                 // no bytes are being assigned a value
  ) {
    // return impossible garbage data.
    DataInfo emptyVar = {UINT8_MAX, UINT8_MAX};
  }

  /*
    1.  Get and dereference the address of a specific byte in allocated 
        memory using `*&memory.address[index];`

        The address needs to be cast as:
          - a non-void pointer in order to access it
          - a pointer type of the correct byte size for the data we're 
              storing
          
        Hence: `*((uint8_t *)&memory.address[index])` ) if it's an 8bit value.
         
    2.  Assign the data from the `data` pointer to memory starting at previously 
        mentioned byte. 
          
        The `data` pointer needs to be cast as a non-void pointer that has 
        the correct byte size to read the value at it's address correctly.
        So: `*(uint8_t *) data` if it's an 8bit value.

    3.  return a struct containing where the data starts and it's size in bytes.
  */

  if(sizeInBytes == 1) {
    *(uint8_t *)&memory.address[index] = *(uint8_t *)data;
  } else if(sizeInBytes == 2) {
    *(uint16_t *)&memory.address[index] = *(uint16_t *)data;
  } else if(sizeInBytes == 4) {
    *(uint32_t *)&memory.address[index] = *(uint32_t *)data;
  } else {
    *(uint64_t *)&memory.address[index] = *(uint64_t *)data;
  }

  DataInfo info = {sizeInBytes, index};

  return info;
}

void freeAllocatedMemory(CustomMemory * memory) {
  // frees dynamically allocated memory and marks the struct as freed.
  free(memory->address);
  memory->size = 0;
  memory->freed = true;
};

void * readData(CustomMemory memory, DataInfo data) {
  // return a void pointer to the data
  switch(data.size) {
    case 1:
      return &memory.address[data.start];
    case 2:
      return &memory.address[data.start];
    case 4:
      return &memory.address[data.start];
    case 8:
      return &memory.address[data.start];
  }
}

void printData(CustomMemory memory, char * formatString, DataInfo data) {
  // grab data from somehwere an allocated memory struct and print it.
  switch(data.size) {
    case 1:
      // convince C data starting at `memory.address[data.start]` is a char
      //printf(formatString, *((char*) &memory.address[data.start]));
      printf(formatString, *(uint8_t *)readData(memory, data));
      break;
    case 2:
      // convince C data starting at `memory.address[data.start]` is a short
      printf(formatString, *(uint16_t *)readData(memory, data));
      break;
    case 4:
      // convince C data starting at `memory.address[data.start]` is a long
      printf(formatString, *(uint32_t *)readData(memory, data));
      break;
    case 8:
      // convince C data starting at `memory.address[data.start]` is a long long
      printf(formatString, *(uint64_t *)readData(memory, data));
      break;
  }
}



int main (void) {
  // Only allowing memory chunks up to 255 bytes, because I don't really need more
  CustomMemory myMemory = allocateCustomMemory(255);
  printf("%i\n", myMemory.size);
  printf("%p\n", myMemory.address);

  // woo! works!
  char myCharacter = 'z';
  // assigns the character to byte 0 of myMemory
  // A 'DataInfo' struct just holds the index and size of some unknown data in myMemory
  DataInfo myCharacterVar = assignToCustomMemory(myMemory, 0, sizeof(myCharacter), &myCharacter);
  printData(myMemory, "%c\n", myCharacterVar);

  // works again!
  // assigns the character to byte 1 of myMemory
  char myCharacter2 = 'g';
  DataInfo myCharacterVar2 = assignToCustomMemory(myMemory, 1, sizeof(myCharacter2), &myCharacter2);
  printData(myMemory, "%c\n", myCharacterVar2);

  // woo!
  // assigns the number to bytes 2-5 of myMemory
  long int myNum = 1000;
  DataInfo myNumVar = assignToCustomMemory(myMemory, 2, sizeof(myNum), &myNum);
  printData(myMemory, "%li\n", myNumVar);

  

  // this doesn't work at all with %s....
  // I can read each individual character though... so all the data is stored.
  char * myString = "hi!";
  DataInfo myStringVar = assignToCustomMemory(myMemory, 3, 4, myString);
  printData(myMemory, "%c\n", myStringVar);
  printf("%c\n", *(char *)&myMemory.address[myStringVar.start + 1]);
  printf("%c\n", *(char *)&myMemory.address[myStringVar.start + 2]);
  // ooo! I can get it to read the whole string! I just have to *not* dereference it.
  printf("%s\n", (char *)readData(myMemory, myStringVar));

  // have to pass a pointer, otherwise the struct is copied and `myMemory.freed` in this scope is not set to `true`
  // (the actual memory *is* freed though)
  freeAllocatedMemory(&myMemory);
  printf("%s", myMemory.freed == 1 ? "true" : "false");



  /*
      ORIGINAL IDEA FOR THIS PROJECT BELOW:
  */

  /*
  // create 256 bytes of free memory at this pointer location:
  char * myMemoryOffset = malloc(256); // make sure this size is less than max unsigned int

  // these "pointers" are 1byte unsigned chars. They can point to 256 different 1-byte memory addresses.
  unsigned char var1 = 0, var2 = 4, var3 = 8;

  // derefence the address at myMemoryOffset[index], and assign a value to it
  // (must case the address a)
  *(int *)&myMemoryOffset[var1] = 5;

  // convince C that the offset of 0 in our memory is an int again, dereferences it, and prints the result.
  printf("%i\n", *((int*) &myMemoryOffset[var1]));
  printf("Size of my memory offset: %i", sizeof(*myMemoryOffset));
  */

  
}