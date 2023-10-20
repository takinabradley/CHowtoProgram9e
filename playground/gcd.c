#include <stdio.h>
#include <limits.h>

int gcd(int x, int y) {
  if (y == 0) return x;
  gcd(y, x % y);
}

int main(void) {
  printf("%d\n", gcd(5, 10));
}
// recursive main test -- I guess it's possible, but it doesn't seem to go on forever even with higher optimization levels.
/* int main(int argc) {
  int count = 0;
  if(argc != 0) {
    count = argc;
  }
  // printf("%d\n", gcd(10, 5));
  if(count == 100) {
    count = 0;
  }

  printf("%d ", ++count);
  main(count);
} */


