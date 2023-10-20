#include <stdio.h>
long int powerRec(int base, int exponent) {
  if(exponent == 0) return 1;
  return base * powerRec(base, exponent - 1);
}

// Defined separately since C doesn't allow default parameter values.
// inteded to be called with `acc` being `1`.
long int powerRecTail(int base, int exponent, long int acc) {
  if(exponent == 0) return acc;
  return powerRecTail(base, exponent - 1, acc * base);
}

// tail call optimized version of recursive exponentation
long int powerRecTCO(int base, int exponent) {
  return powerRecTail(base, exponent, 1);
}

int main(void) {
  printf("%ld", powerRecTCO(5, 5));
}