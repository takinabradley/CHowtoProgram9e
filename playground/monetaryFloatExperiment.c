#include <stdio.h>
#include <float.h>

int main(void) {
  float sixSignificantDigits = 9999.00f;

  // makes the number 7 significant digits, causing it to start losing accuracy
  sixSignificantDigits = sixSignificantDigits + 1.01f;

  
  printf("%.2f", sixSignificantDigits);
}