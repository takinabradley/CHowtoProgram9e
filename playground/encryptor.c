
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


short int getDigitAtPosition(short position, short number) {
  // prevent -infinity from next operation while getting same result
  if(number == 0) number = 1; 

  // get number of digits in the int
  short int digits = floor(log10(abs (number))) + 1;

  // if the position doesn't exist, return -1
  if(position > digits || position < 0) return -1;

  // if the position is 1, the first digit on the right side is `abs(number % 10)`
  if(position == 1) return abs(number % 10);
  
  // if the position is higher than one, divide the number by increasing powers 
  // 10 first, so that getting the remainder of dividing by ten gives us the 
  // number at a given position
  return abs((number / (int) pow(10, position - 1)) % 10);
}

short int encrypt(short int digit) {
  //  transform numbers by
  //  1. adding 7
  //  2. getting remainder of 10
  return (digit + 7) % 10;
}

/* short int swapFirstWithThirdAndSecondWithFourth(short int num1, short int num2, short int num3, short int num4) {

} */

int main(void) {
  short int input = 0;
  //  accept a 4-digit integer
  printf("%s", "Please enter a 4-digit integer: ");
  scanf("%d", &input);

  // get numbers in each position (right -> left)
  short int firstNumber = encrypt(getDigitAtPosition(1, input));
  short int secondNumber = encrypt(getDigitAtPosition(2, input));
  short int thirdNumber = encrypt(getDigitAtPosition(3, input));
  short int fourthNumber = encrypt(getDigitAtPosition(4, input));

  // swap the first and third digit
  // swap the second and fourth digit
  // display result to user
  printf("Encrypted Number: %d%d%d%d\n", secondNumber, firstNumber, fourthNumber, thirdNumber);
}

