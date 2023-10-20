#include <stdio.h>
#include <stdlib.h>
char * makeString() {
  return "hello";
}
char * returnString() {
  char * string = "Hello";
  return string;
}

int returnNum() {
  return 1;
}

int main(void) {
  //char * thing = makeString();
  //printf("%s", thing);
  int num = 5;
  char test[] = "Hello there";
  printf("%s", test);

  char * canIfree = "HELOOOOOOO";
  char * string = returnString();
  printf(string);
  int returnedNum = returnNum();
  printf("%d", returnedNum);
}