#include <stdio.h>

enum Status {CONTINUE, WON, LOST};

int main() {
  enum Status gameStatus = WON;

  int thing = 0;

  printf("%d\n", gameStatus);
}