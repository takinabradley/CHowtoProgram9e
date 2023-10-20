#include <stdio.h>
#include <stdlib.h>

char* something(void) {
  char x[3];
  x[0] = 'a';
  x[1] = 'b';
  x[2] = 'c';
  return x;
}

int main(void) {
  char * addr = something();
  printf("%d", addr);
}