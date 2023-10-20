#include <stdio.h>

double hypotenuse(double a, double b) {
  return a * a + b * b;
}

int main(void) {
  printf("%f\n", hypotenuse(3, 4));
  printf("%f\n", hypotenuse(5, 12));
  printf("%f\n", hypotenuse(8, 15));
}