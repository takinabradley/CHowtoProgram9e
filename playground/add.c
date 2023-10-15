// fig03_02.c
// Class average program with counter-controlled iteration.
#include <stdio.h>
#include <stdbool.h>

// function main begins program execution
int main(void) {
  // initialization phase
  int total = 0; // initialize total of grades to 0
  int counter = 0; // number of the grade to be entered next
  int isMoreGrades = 1;

  // processing phase
  while (isMoreGrades) { // loop 10 times
    int grade = 0; // grade value
    printf("%s", "Enter grade (or -1 if no grade): "); // prompt for input
    scanf("%d", &grade); // read grade from user

    if(grade == -1) {
      isMoreGrades = 0;
      break;
    } 
    
    total = total + grade; // add grade to total
    counter = counter + 1; // increment counter
  } // end while

  // termination phase
  if(counter > 0) {
    double average = (double) total / counter; // integer division
    printf("Class average is %.2f\n", average); // display result
  } else {
    puts("No grades entered");
  }
  
  
} // end function main