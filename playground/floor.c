#include <stdio.h>
#include <math.h>

int main(void) {
  // round to down to 1
  printf("%f\n", floor(1 + .6));

  // round to 10ths place
  printf("%f\n", floor(1.67 * 10) / 10);
}