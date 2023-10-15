#include <stdio.h>
int squareInt(int number); // function prototype

int main(void) {
  for (int x = 1; x <= 20; ++x) {
    printf("%d\t", squareInt(x));
  }
  puts("");
}

int squareInt(int number) {
  return number * number;
}

