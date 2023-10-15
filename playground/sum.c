#include <stdio.h>
void consumeStdin(void);
int promptForInt(void);
int addInputtedNumbers(short int amountOfNums);

int main(void) {
  // prompt for amount of numbers user wants to add
  printf("%s", "Please enter the amount of numbers you'd like to add: \n");
  short numsToAdd = promptForInt();

  // prompt user to enter the numbers
  printf("%s%d%s\n", "Please input ", numsToAdd, " numbers");
  int total = addInputtedNumbers(numsToAdd);

  // print the sum of the numbers
  printf("Sum of numbers: %d\n", total);
}

void consumeStdin(void) {
  while(getchar() != '\n') { 
    /* consume characters in stdin until a newline is consumed*/
  }
}

int promptForInt(void) {
  int numsToAdd = 0;
  
  while(scanf("%i", &numsToAdd) == EOF) {
    puts("Please try again!");
    consumeStdin();
  }
  return numsToAdd;
}

int addInputtedNumbers(short int amountOfNums) {
  long int sum = 0;
  for(short i = 0 ; i < amountOfNums; ++i) {
    int amount = 0;

    if(scanf("%d", &amount) == EOF) {
      puts("Not a number, please try again!");
      consumeStdin();
      continue;
    } else {
      sum += amount;
    }
  }

  return sum;
}