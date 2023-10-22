/* 
  This code attemps to dynamically allocate a chunk of memory with `malloc`, 
  then manually manipulates and stores multiple values in that memory.
*/
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef struct {
  uint8_t size;
  uint8_t * address;
  bool freed;
} ManualMemory;

typedef struct {
  uint8_t size;
  uint8_t start;
} ManualPointer;

ManualMemory allocateManualMemory(uint8_t size) {
  // dynamically allocates a chunk of memory and packages it in a struct.
  ManualMemory theManualMemory = {size, malloc(size), false};
  return theManualMemory;
}

ManualPointer assignToManualMemory(ManualMemory memory, uint8_t index, uint8_t sizeInBytes, char * data) {
  // assigns a value somewhere in an ManualMemory object for use later.

  if (
    // index is out of bounds
    index > memory.size - 1 ||                      
    index + 1 < 1 ||
    // the amount of bytes from the index will exceed bounds
    index + (sizeInBytes - 1) > memory.size - 1 ||
    // no bytes are being assigned a value
    // NOTE: 1 is added to both sides of this check since sizeInBytes can't be 0
    sizeInBytes + 1 < 1 
  ) {
    // return impossible garbage data.
    ManualPointer emptyPointer = {UINT8_MAX, UINT8_MAX};
    return emptyPointer;
  }

  /*  Assigning Data To An Arbitrary Spot In Allocated Memory (a how-to guide):

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
        (for future reads/writes)
  */

  // THIS WORKS! Push the data onto the memory location one byte at a time.
  // No compiler warnings, no problem.
  for(uint8_t i = 0; i < sizeInBytes; i++) {
    *(uint8_t *)&memory.address[index + i] = *(uint8_t *)&data[i];
  }

  ManualPointer info = {sizeInBytes, index};
  return info;
}

void freeManualMemory(ManualMemory * memory) {
  // frees dynamically allocated memory and marks the struct as freed.
  free(memory->address);
  memory->size = 0;
  memory->freed = true;
}

void * readData(ManualMemory memory, ManualPointer data) {
  // return a void pointer to the data. 
  // It can then be read with the info in the ManualPointer struct.
  return &memory.address[data.start];
}

void printData(ManualMemory memory, char * formatString, ManualPointer data) {
  // grab read data from ManualMemory and print it using printf
  switch(data.size) {
    case 1:
      // convince C data starting at `memory.address[data.start]` is 1 byte
      printf(formatString, *(uint8_t *)readData(memory, data));
      break;
    case 2:
      // convince C data starting at `memory.address[data.start]` is 2 bytes
      printf(formatString, *(uint16_t *)readData(memory, data));
      break;
    case 4:
      // convince C data starting at `memory.address[data.start]` is 4 bytes
      printf(formatString, *(uint32_t *)readData(memory, data));
      break;
    case 8:
      // convince C data starting at `memory.address[data.start]` is 8 bytes
      printf(formatString, *(uint64_t *)readData(memory, data));
      break;
  }
}



int main (void) {
  // Only allowing memory chunks up to 255 bytes, because I don't really need more
  ManualMemory myMemory = allocateManualMemory(255);
  printf("%i\n", myMemory.size);
  printf("%p\n", myMemory.address);


  char myCharacter = 'z';
  char myCharacter2 = 'g';
  long int myNum = 1000;
  char * myString = "Hey! My name is billy ray!";



  // assigns the character to byte 0 of myMemory
  // A 'ManualPointer' struct just holds the index and size of some unknown data in myMemory
  ManualPointer myCharacterPointer = assignToManualMemory(myMemory, 0, sizeof(myCharacter), &myCharacter);
  ManualPointer myCharacterPointer2 = assignToManualMemory(myMemory, 1, sizeof(myCharacter2), &myCharacter2);

  // runtime check complains about alignment when assigning 64-bit integers, 
  // so we assign it to index 8. C seems to like the number 8.
  // (-fsanitize=address,undefined) <-- said runtime check.
  // - - - - - 
  // must assign to char pointer to void compiler complaints... 
  // the compiler doesn't complain though... so that must mean it's a-okay?
  // (this is probably undefined behavior)
  ManualPointer myNumPointer = assignToManualMemory(myMemory, 8, sizeof(myNum), (char *)&myNum);

  ManualPointer myStringPointer = assignToManualMemory(myMemory, 16, strlen(myString) + 1, myString);

  
  printData(myMemory, "%c\n", myCharacterPointer);  // works!
  printData(myMemory, "%c\n", myCharacterPointer2); // works again!
  printData(myMemory, "%li\n", myNumPointer);       // works thrice!

  // can even print chars in strings/whole strings!
  printf("%s\n", (char *)readData(myMemory, myStringPointer)); // read string (must not dereference)
  printf("%c\n", *(char *)&myMemory.address[myStringPointer.start + 0]);  // print first char
  printf("%c\n", *(char *)&myMemory.address[myStringPointer.start + 1]);  // print second

  // have to pass a pointer, otherwise the struct is copied and `myMemory.freed` in this scope is not set to `true`
  // (the actual memory *is* freed though)
  freeManualMemory(&myMemory);
  printf("%s", myMemory.freed == 1 ? "true" : "false");


  /*
      ORIGINAL IDEA FOR THIS PROJECT BELOW:
  */

  /* // supposedly this is undefined behavior, but it works on my system lol
  // I should look into it (actually learn more C)

  // create 256 bytes of free memory at this pointer location:
  char * myMemoryOffset = malloc(256); // make sure this size is less than max unsigned int

  // these "pointers" are 1byte unsigned chars. They can point to 256 different 1-byte memory addresses.
  unsigned char var1 = 0, var2 = 4, var3 = 8;

  // derefence the address at myMemoryOffset[index], and assign a value to it
  // (must case the address a)

  // This is will a warning if myMemoryOffset is a void pointer.
  // It WORKS, but you must disable GCC warnings. 
  // I feel I'd like it to be void, but `uint8_t *`or `char` work as well, I suppose.
  *(int *)&myMemoryOffset[var1] = 5;

  // convince C that the offset of 0 in our memory is an int again, dereferences it, and prints the result.
  printf("%i\n", *((int*) &myMemoryOffset[var1]));
  printf("Size of my memory offset: %i", sizeof(*myMemoryOffset)); */
 

  
}