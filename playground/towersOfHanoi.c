#include <stdio.h>
#include <limits.h>
#include <math.h>

void towersOfHanoi(int disksToMove, int startingPeg, int endingPeg, int intermediatePeg) {
  if(disksToMove == 1) {
    printf("%d -> %d | ", startingPeg, endingPeg);
    return;
  }

  // move all but one disk from starting peg -> intermediate, using ending as storage
  towersOfHanoi(disksToMove - 1, startingPeg, intermediatePeg, endingPeg);

  // move the last disk from starting peg -> ending (intermediate unused here)
  towersOfHanoi(1, startingPeg, endingPeg, intermediatePeg);

  // move the disks still on intermediate peg -> ending, using starting peg as storage
  towersOfHanoi(disksToMove - 1, intermediatePeg, endingPeg, startingPeg);
}

void longlongiteration(unsigned long long int counter) {
  while(counter != 0) {--counter;}
}

int main(void) {
  towersOfHanoi(16, 1, 3, 2);
  puts("");
}
