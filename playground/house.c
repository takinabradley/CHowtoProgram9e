#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
  int SquareFeet;
  int NumBedrooms;
  int NumBaths;
} House;

void printHouse(House house) {
  printf("{\n\
  SquareFeet: %d\n\
  NumBedrooms: %d\n\
  NumBaths: %d\n\
}\n", 
  house.SquareFeet, 
  house.NumBedrooms, 
  house.NumBaths
  );
}

/* void printHouse(House * house) {
  printf("{\n\
  SquareFeet: %d\n\
  NumBedrooms: %d\n\
  NumBaths: %d\n\
}\n", 
  house->SquareFeet, 
  house->NumBedrooms, 
  house->NumBaths
  );
} */

void * MyAlloc(size_t size) {
  return malloc(size);
}

int getBedrooms(House * house) {
  return house->NumBedrooms;
}

int main(void) {
  // *string and string[0] are the same for character arrays and a char pointer
  char * string = "hello";
  /* char charArray[] = {'h', 'e', 'l', 'l', 'o', '\0'};

  printf("First character of literal: %c\n", *string);
  printf("First character of array %c\n", charArray[0]);
  printf("First character of literal 2: %c\n", string[0]);
  printf("First character of array 2: %c\n", *string);

  // printf expects a character array, or a char pointer for strings.
  printf("%s\n", string);
  printf("%s\n", charArray);

  // this is not allowed- it's not a char array
  // printf("%s", 'c'); 

  char myChar = 'c';
  char * pMyChar = &myChar;
  // this will print garbage, it's not null terminated.
  printf("%s\n", pMyChar);

  printf("String size: %d\nArray size: %d\n", sizeof(string), sizeof(charArray)); */


  /* long long unsigned int num = 140733538785592;
  printf("Num location %lld\n", &num);
  printf("num %lld\n", num);
  void * somewhere = (void *) num;
  printf("void location %lld\n", somewhere);
  printf("value at location: %d", *(long long int *)somewhere); */
  //int * pNum = &num;
  //*pNum = 1;
  // printf("%d", num);
  //void * longlongPointer = (void*) num;
  //printf("%p", longlongPointer);
  /* House myHouse = {1200, 2, 1};



  House *pMyHouse = &myHouse;
  printf("My house's address is: %p\n", &myHouse);
  printf("The pointer holds it's address! See? %p\n", pMyHouse);
  printf("The pointer is here, though: %p\nI'm giving it to you :)\n\n", &pMyHouse);
  puts("My house has these features!");
  printHouse(*pMyHouse);

  // create a pointer to a character string
  char *charString = "Hello World!";

  // create a pointer that points to the character string pointer
  char ** pCharString = &charString;


  printf("- The character string lives here: %p\n\n", charString);
  printf("- The pointer to the character string lives here: %p\n\n", &charString);
  printf("- The second pointer pointing to the original lives here: %p\n\n", &pCharString);
  printf("- The second pointer's value is just an address to the first pointer': %p\n\n", pCharString);
  printf("- dereferencing the second pointer gives me the location of the character string %p\n\n", *pCharString);
  printf("- dereferencing the second pointer and getting it's address (*&) just gives me it's value (the address of the first pointer): %p\n\n", *&pCharString);
  printf("- I can print the original string using the second pointer by dereferencing it (so it points to the string memory and not the original pointer memory): %s\n\n", *pCharString);
  printf("- I can print the original string with the original pointer without dereferencing it (since it already points to the string memory): %s\n\n", charString);
  printf("a char: %c\n", charString[0]);
  // random garbage until it has an address assigned to it;
  char * uninitialized;

  int * null = (int *) 0; // null pointer? idunno.

  // void pointer
  void * thing = (void *) 1;
  int * myThing = (int *) thing; // can cast a void * to a pointer of any type you wish.
  printf("Int from null pointer: %d\n", myThing);

  // example 2 -- void * 
  House * pHouseFromMyAlloc = (House *) MyAlloc(sizeof(House));

  // function pointer
  void (*pPrintHouse)(House house) = printHouse;
  puts("Print from function pointer:");
  (*pPrintHouse)(*pHouseFromMyAlloc); */
}