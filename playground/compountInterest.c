// gcc: must include -lm flag for the libm.a file
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(void) {
  int investment = 1000;
  double interest = .05;

  int numberOfYears = 10;
  // output formatted column heads
  // Makes the 'year' column 4 chars wide, and the `Amount` column 21 chars wide (to match the strings)
  printf("%4s%21s\n", "Year", "Amount on deposit");

  for(int currentYear = 1; currentYear <= numberOfYears; ++currentYear) {
    // explicitly cast variables, though it's not needed (will happen implicitly)
    double amount = (double) investment * pow(1 + interest, (double) currentYear);

    // format the columns for the output as well. Content that is too small gets left-padded.
    // (can right-pad by doing `%-<field-width>`)
    printf("%4d%21.2f\n", currentYear, amount);
  }


}