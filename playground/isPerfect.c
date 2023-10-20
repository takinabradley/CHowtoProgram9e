#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// I don't know how to create and use arrays in c yet... but this would likely
// be useful to find the next perfect number faster.
void getDivisors(unsigned long int num) {
  const unsigned long int limit = sqrt(num);
  for(unsigned long int i = 1; i <= limit; ++i) {
    

    if(num % i == 0) {
      printf("%10lu\n", num / i);
      if(i != num / i) printf("%10lu\n", i);

      /* if(i == num / i) {
        printf("%10llu\n", num / i);
      } else {
        printf("%10llu\n", i);
        printf("%10llu\n", num / i);
      } */
      

    }
    
  }
  puts("");
}

bool isPerfect(unsigned long int num) {
  unsigned long int sum = 0;

  // sum all divisors of num (except for itself)
  // the largest divisor of a given number is always <= number / 2.
  for(unsigned long int i = 1; i <= num / 2; i++) {
    if(num % i == 0) sum += i;
  }

  // if the sum of all divisors is the number, the number is perfect.
  return sum == num;
}

void printPerfectUpToNum(unsigned long int num) {
  for(unsigned long int i = 1; i <= num; ++i) {
    if(isPerfect(i) == 1) printf("%d\n", i);
  }
}

int main(void) {
  // puts(isPerfect(28 ? "true" : "false"));
  // printPerfectUpToNum(1000000);
  getDivisors(8128);
}

