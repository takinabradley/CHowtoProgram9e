#include <stdio.h>
#include <stdlib.h>
#include <time.h>


enum ToriseMoves {SLIP = -6, SLOW_PLOD = 1, FAST_PLOD = 3};
int randomTortiseMove() {
  char move = rand() % 10 + 1;
  switch(move) {
    case 1:             // 50% chance
    case 2:
    case 3:
    case 4:
    case 5:
      return FAST_PLOD;
    case 6:             // 30% chance
    case 7:
    case 8:
      return SLOW_PLOD;
    case 9:             // 20% chance
    case 10:
      return SLIP;
  }
}

enum HareMoves {BIG_SLIP = -12, SMALL_SLIP = -2, SLEEP = 0, SMALL_HOP = 1, BIG_HOP = 9};
int randomHareMove() {
  char move = rand() % 10 + 1;
  switch(move) {
    case 1:             // 50% chance
    case 2:
    case 3:
      return SMALL_HOP;
    case 4:             // 20% chance
    case 5:
      return SLEEP;
    case 6:             // 20% chance
    case 7:
      return BIG_HOP;
    case 8:             // 20% chance
    case 9:
      return SMALL_SLIP;
    case 10:            // 10% chance
      return BIG_SLIP;
  }
}

void printLine(char playerSymbol, char position) {
  for(char i = 0; i < 70; ++i) {
    if(i == position) {
      printf("%c", playerSymbol);
    } else {
      printf("%c", '-');
    }
  }
}

typedef struct {
  char position;
} Player;

void race() {
  srand(time(NULL));
  time_t currentSecond = time(NULL);
  const char START_SQUARE = 1;
  const char END_SQUARE = 70;
  Player tortise = {START_SQUARE};
  Player hare = {START_SQUARE};

  printf("%-21s\n", "ON YOUR MARK, GET SET");
  printf("%-17s%4s\n", "BANG", "!!!!");
  printf("%-17s%4s\n", "AND THEY'RE OFF", "!!!!");

  while(tortise.position != END_SQUARE && hare.position != END_SQUARE) {
    if(currentSecond != time(NULL)) {
      currentSecond = time(NULL);
      const char harePreviousPosition = hare.position;
      const char toritsePreviousPosition = tortise.position;
      tortise.position += randomTortiseMove();
      hare.position += randomHareMove();

      if(hare.position > END_SQUARE) hare.position = harePreviousPosition;
      if(hare.position < START_SQUARE) hare.position = START_SQUARE;
      if(tortise.position > END_SQUARE) tortise.position = toritsePreviousPosition;
      if(tortise.position < START_SQUARE) tortise.position = START_SQUARE;
      
      printLine('T', tortise.position);
      puts("");
      printLine('H', hare.position);
      puts("\n");
    }
  }

  if(hare.position == END_SQUARE && tortise.position == END_SQUARE) {
    puts("TIE");
  } else if (hare.position == END_SQUARE) {
    puts("HARE");
  } else {
    puts("TORTISE");
  }
}

int main(void) {
  race();
}