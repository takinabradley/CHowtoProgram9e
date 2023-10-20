#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {
  srand(time(NULL));
    // print even numbers up to 10
  printf("even: %d\n", (rand() % 5 + 1) * 2);

  // print odd numbers up to 11
  printf("odd: %d\n", ((rand() % 5 + 1) * 2) + 1);

  // print from set 6, 10, 14, 18, 22
  printf("set [6, 10, 14, 18, 22]: %d\n", (((rand() % 5 + 1) * 2) + 1) * 2);
}
