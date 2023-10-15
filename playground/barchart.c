#include <stdio.h>

int main(void) {
  const int MAX_NUMBERS = 5;
  const int MAX_NUMBER_VALUE = 30;
  const int MIN_NUMBER_VALUE = 1;
  int currentNumber = 0;

  // Bah, I wish I knew how to make arrays ;-;
  int num1 = 0;
  int num2 = 0;
  int num3 = 0;
  int num4 = 0;
  int num5 = 0;
  
  // collect results of five numbers:
  puts("Please enter 5 numbers between 1 and 30 (press enter after each number):");
  int input = 0;
  while(currentNumber != MAX_NUMBERS) {
    int scanfResult = scanf("%d", &input);

    // if input was assigned successfully, and it's within range
    if(scanfResult == 1 && input <= MAX_NUMBER_VALUE && input >= MIN_NUMBER_VALUE) {
        // choose value to assign...
        switch (currentNumber) {
          case 0:
            num1 = input;
            break;
          case 1:
            num2 = input;
            break;
          case 2:
            num3 = input;
            break;
          case 3:
            num4 = input;
            break;
          case 4:
            num5 = input;
            break;
        }

        // .. then increment number of numbers inputted
        ++currentNumber;
    } else {
      // otherwise clear stdin buffer in case of bad input
      puts("Not a value between 1 and 30!");
      while(getchar() != '\n') {}
    }
  }
  
  // create a separator between input and output
  puts("\n    ------------------------------    \n");

  // output bar graph for each number
  for(int i = 0; i < MAX_NUMBERS; ++i) {
    switch (i) {
      case 0:
        printf("%d:\t", num1);
        for(int j = 0; j < num1; ++j) printf("%c", '*');
        break;
      case 1:
        printf("%d:\t", num2);
        for(int j = 0; j < num2; ++j) printf("%c", '*');
        break;
      case 2:
        printf("%d:\t", num3);
        for(int j = 0; j < num3; ++j) printf("%c", '*');
        break;
      case 3:
        printf("%d:\t", num4);
        for(int j = 0; j < num4; ++j) printf("%c", '*');
        break;
      case 4:
        printf("%d:\t", num5);
        for(int j = 0; j < num5; ++j) printf("%c", '*');
    }

    // separate each graph by a couple new lines
    puts("\n");
  }
}