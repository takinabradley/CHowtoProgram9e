#include <stdio.h>
int maximum(int x, int y, int z);

int main(void) {
  int num1 = 0; 
  int num2 = 0;
  int num3 = 0;
  
  puts("Please enter three integers");
  while(scanf("%d%d%d", &num1, &num2, &num3) != 3) {
    puts("Please enter three integers:");
    while(getchar() != '\n') {/* clear stdin buffer in case of bad input */};
  }

  printf("Integers entered: %d %d %d\n", num1, num2, num3);
  printf("Max value: %d\n", maximum(num1, num2, num3));
}

int maximum(int x, int y, int z) {
  if(x > y && x > z) return x;
  if(y > x && y > z) return y;
  return z;
}