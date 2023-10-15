// fig02_01.c
// A first program in C.
#include <stdio.h>
#include <limits.h>

// function main begins program execution
int main(void) {
  const double BONUS_THRESHOLD = 0.8; // more than 80% must pass to get a bonus
  int pass = 0;
  int fail = 0;
  int total = 0;
  int input = 0;

  puts("Real Estate Broker Exam Summifier\n");
  puts("Please enter the number '1' for pass, or '2' for fail.\n");
  puts("Enter -1 when all tests results have been entered\n");

  printf("%s", "1(pass) / 2(fail) / -1(done): ");
  scanf("%d", &input);

  while(input >= 0) {
    if(input != 1 && input != 2 && input != -1) {
      printf("'%d' is not a valid option\n", input);
    } else if (input == 1) {
      ++pass;
    } else if (input == 2) {
      ++fail;
    }

    printf("%s", "1(pass) / 2(fail) / -1(done) : ");
    scanf("%d", &input);    
  }
  
  // https://wiki.sei.cmu.edu/confluence/display/c/ -- integer overflow (check later, currently unavailable)
  if ( pass > INT_MAX - fail) {
    puts("YOU'VE CALCULATED TOO MUCH, INTEGER OVERFLOW!");
    return 1;
  }
  
  total = pass + fail;
  printf("Pass %d\n", pass);
  printf("Fail %d\n", fail);
  printf("total %d\n", total);
  if(((double) pass / total) > BONUS_THRESHOLD) puts("Bonus to instructor!");
} // end function main
