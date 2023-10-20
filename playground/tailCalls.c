#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned long long int fact(int num) {
  if(num < 0) {
    printf(
      "Function `fact` expected a positive integer, but recieved: %d\n",
      num
    );
    exit(1);
  }

  if(num == 1 || num == 0) return 1; 
  return num * fact(num - 1);
}

/* 
// this is about the  best you can do with a single function in C (two arguments required).

unsigned long long int facttail(int num, unsigned long long int acc) {
  if(num == 0) return acc;
  return facttail(num - 1, num * acc);
} */

int factTail(int num, unsigned long long int acc) {
  // tracks an accumulator for TCO reasons
  // defining this function separately lets us assign to it a default value of 1
  // without the consumer of the function being involved.
  if(num == 0) return acc;
  return factTail(num - 1, num * acc);
}

// best compile options to debug TCO functions such as this might be as below:
// -Og -- optimize debug (The default option -O0 doesn't seem to allow enabling TCO optimization).
// -foptimize-sibling-calls -- enable TCO optimization
// gcc -std=c18 factorial.c -Og -foptimize-sibling-calls
int doesGCCDoTCO(int num) {
  // this should infinite loop and not segfault if it does
  if(num == INT_MAX) {
    num = 0;
  }
  return doesGCCDoTCO(num + 1);
}

unsigned long long int factorialTCO(int num) {
  return factTail(num, 1);
}


unsigned long long fibonacci_tail(int position, unsigned long long current, unsigned long long next) {
  // this is a tail call for the TCO optimized version of fibonacci.
  // It's defined separately to be called by finonacciTCO because default values
  // cannot be supplied in C.
  if (position == 0) return current;
  if (position == 1) return next;

  // this function also doesn't operate in 2^n, like the 'normal' one. 
  // It's instead supplied with the first two digits, and 'maths it out' every
  // call
  return fibonacci_tail(position - 1, next, current + next);    
}

unsigned long long int fibonacciTCO(int num) {
    return fibonacci_tail(num, 0, 1);
}

unsigned long long int fib(int num) {
  if(num == 0) return 0;
  if(num == 1) return 1;
  return fib(num - 1) + fib(num - 2);
}

int main(void) {
  unsigned long long value = fact(10);
  printf("%d\n", value);
  printf("%d\n", fib(10));
  printf("%d\n", fibonacciTCO(65536));
  printf("%d\n", factorialTCO(10));
}

