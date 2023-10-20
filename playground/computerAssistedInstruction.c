#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

/* ----- IO ----- */
void clearStdinBuffer() {
  // prevents scanf from tripping up in a while loop.
  while(getchar() != '\n') {/* consumes buffer until a newline is consumed */}  
}

int promptForNumber(char * message, int minValue, int maxValue) {
  int userInput = 0;

  puts(message);
  while(scanf("%d", &userInput) != 1 || (userInput < minValue || userInput > maxValue)) {
    puts("Unexpected input! Please, try again.");
    clearStdinBuffer();
  }

  return userInput;
}

void printResults(int questionsAsked, float questionsRight, float questionsWrong) {
  printf("%5s\t%7s\t%9s\n", "Asked", "Correct", "Incorrect");
  printf("%5d\t%7.2f\t%9.2f\n", questionsAsked, questionsRight, questionsWrong);
  if(questionsRight / questionsAsked > 0.75) {
    puts("GREAT JOB! YOU'RE READY TO ADVANCE");
  } else {
    puts("Please ask your teacher for extra help!");
  }
}

char * promptForOperator(){
  char userInput = 'z';
  srand(time(NULL));
  puts("Choose a question type (type '+', '-', '*', or 'a' for any)");
  clearStdinBuffer(); // I don't know why I have to do this, but it doesn't work without it.
  while(
    scanf("%c", &userInput) != 1 ||
    (userInput != '+' &&
    userInput != '-' &&
    userInput != '*' &&
    userInput != 'a')
  ) {
    //puts("wtf");
    puts("Unexpected input! Please, try again.");
    clearStdinBuffer(); // for some reason, this doesn't seem to work properly in this instance..
  }
  //puts("got here");
  if(userInput == '+') return "+";
  if(userInput == '-') return "-";
  if(userInput == '*') return "*";
  if(userInput == 'a') return "any";
}
/* ----- -- ----- */


char * buildMathQuestion(int num1, int num2, char* operator) {
  // uhhh, something about this is probably not quite right.

  char *str = malloc(20);
  char num1String[4];
  char num2String[4];

  sprintf(num1String, "%d", num1);
  sprintf(num2String, "%d", num2);

  strcat(str, "What is ");
  strcat(str, num1String);
  strcat(str, " ");
  strcat(str, operator);
  strcat(str, " ");
  strcat(str, num2String);
  strcat(str, "? ");

  return str;
}

char * randomSuccessMessage() {
  switch(rand() % 4 + 1) {
    case 1:
      return "Very good!";
    case 2:
      return "Excellent";
    case 3:
      return "Nice work!";
    case 4:
      return "Keep up the nice work!";
  }
}

char * randomFailureMessage() {
  switch(rand() % 4+ 1) {
    case 1:
      return "No. Please try again.";
    case 2:
      return "Wrong. Try once more.";
    case 3:
      return "Don't give up!";
    case 4:
      return "No. Keep trying.";
  }
}

char * randomOperator() {
  switch(rand() % 3+ 1) {
    case 1:
      return "+";
    case 2:
      return "-";
    case 3:
      return "*";
  }
}

int computeSolution(int x, int y, char * operator) {
  if(operator == "+") return x + y;
  if(operator == "-") return x - y;
  if(operator == "+") return x * y;
}

bool playMathGame(int numberOfQuestions, int difficulty, char * operatorType) {
  int incorrectAnswers = 0;
  int correctAnswers = 0;
  
  // ask given amount of questions.
  for(int i = 0; i < numberOfQuestions; ++i) {
    bool firstTry = true;
    int answer = 999; // initialize with impossible solution;
    const int num1 = rand() % (int) pow(10, difficulty);
    const int num2 = rand() % (int) pow(10, difficulty);
    char * operator = operatorType == "any" ? randomOperator() : operatorType;
    const int solution = computeSolution(num1, num2, operator);

    char * message = buildMathQuestion(num1, num2, operator);
    // ask each question until the user gets it correct.
    while(answer != solution) {
      answer = promptForNumber(message, INT_MIN, INT_MAX);
      if (answer == solution) {
        puts(randomSuccessMessage());
        // if answered correct on first try, add it as correct
        if(firstTry) ++correctAnswers; 
      } else {
        puts(randomFailureMessage());
        if(firstTry) {
          // if answered incorrect first try, add as incorrect...
          ++incorrectAnswers;
          // ... then set the firstTry flag to false so it's not counted again.
          firstTry = false;  
        }
      }
    }

    free(message);
  }

  printResults(numberOfQuestions, correctAnswers, incorrectAnswers);
}


int main (void) {
  const int numOfQuestions = promptForNumber(
    "How many questions would you like to do? (under 100): ",
    1,
    100
  );

  const int difficulty = promptForNumber(
    "Please select a difficulty (1, 2, or 3): ",
    1,
    3
  );
  
  char *operator = promptForOperator();
  playMathGame(numOfQuestions, difficulty, operator);
}