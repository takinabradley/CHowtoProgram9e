#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* 
  
  This function cannot be used to grab number positions on encrypted input, 
  since encrypted integers have the possibility of starting with leading '0's.

short int getDigitAtPosition(short position, short number) {
  // prevent -infinity from next operation while getting same result
  if(number == 0) number = 1; 

  // get number of digits in the int
  short int digits = floor(log10(abs (number))) + 1;
  printf("digits is: %d", digits);
  // if the position doesn't exist, return -1
  if(position > digits || position <= 0) return -1;

  // if the position is 1, the first digit on the right side is `abs(number % 10)`
  if(position == 1) return abs(number % 10);
  
  // if the position is higher than one, divide the number by increasing powers 
  // 10 first, so that getting the remainder of dividing by ten gives us the 
  // number at a given position
  return abs((number / (int) pow(10, position - 1)) % 10);
} */

short int decrypt(short int encryptedDigit) {
  // Each number was encrypted via originalNum + 7 % 10
  if(encryptedDigit < 7) {
    // if the encrypted number is less than 7, add 10 back to it before subtracting 7
    return encryptedDigit + 10 - 7;
  } else {
    // otherwise, there's no need to add 10 back, and we can just subtract 7
    return encryptedDigit - 7;
  }
}


int main(void) {
  short int firstNum = 0;
  short int secondNum = 0;
  short int thirdNum = 0;
  short int fourthNum = 0;
  //  accept a 4-digit number (save them right -> left)
  printf("%s", "Please enter a 4-digit number to decrypt: ");
  scanf("%1d%1d%1d%1d", &fourthNum, &thirdNum, &secondNum, &firstNum);
  
  
  firstNum = decrypt(firstNum);
  secondNum = decrypt(secondNum);
  thirdNum = decrypt(thirdNum);
  fourthNum = decrypt(fourthNum);

  // swap the first and third digit
  // swap the second and fourth digit
  // display result to user
  printf("Decrypted Num: %d%d%d%d\n", secondNum, firstNum, fourthNum, thirdNum);
}

