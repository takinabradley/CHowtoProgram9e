// pythagoreanTriples.c
// find all Pythagorean triples for side1, side1, and the hyponuse no larger than 500
// use a triple-nested `for` loop that tried all possibilities.

// a^2 + b^2 = c^2

#include <stdio.h>
#include <limits.h>

void printPythagoreanTriples(short int maxSideLength) {
  long int possibilitiesFound = 0;

  for(short int a = 1; a < maxSideLength; ++a) {
    for(short int b = 1; b < maxSideLength; ++b) {
      for (short int c = 1; c < maxSideLength; ++c) {
        long int aSquared = a * a;
        long int bSquared = b * b;
        long int cSquared = c * c;
        
        if(aSquared + bSquared == cSquared) {
          ++possibilitiesFound;
          printf("a: %3d\t\tb: %3d\t\tc: %3d\n", a, b, c);
        }
      }
    }
  }
  
  puts("\nPossibilities found:");
  printf("%-9d\n", possibilitiesFound);
}

int main(void) {
  printPythagoreanTriples(500);
}

