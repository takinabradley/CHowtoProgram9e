#include <stdio.h>

int main(void) {
  int sum = 0;
  int totalNumbers = 0;

  puts("Please input some numbers to average");
  int input = 0;
  while (input != 9999) {
    int scanfResult = scanf("%d", &input);

    if(scanfResult == 1 && input != 9999) {
      ++totalNumbers;
      sum += input;
    } else {
      // consume until next newline in stdin (just in case a bad value is entered)
      while(getchar() != '\n') {}
    }
  }

  if (totalNumbers > 0) {
    printf("The average of all numbers is %.2f\n", (double) sum / totalNumbers);
  } else {
    puts("No numbers to calculate!");
  }

}