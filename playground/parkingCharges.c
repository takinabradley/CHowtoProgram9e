#include <stdio.h>
#include <math.h>


float chargeParking(float hours) {
  const float MAX_CHARGE = 10.00;

  // $2 flat fee for three hour parking.
  float charge = 2.00;

  // if parked more than three hours, start charging .50 for any additional time
  if(hours > 3.00) {
    charge += (hours - 3) * .50; // otherwise, charge 
  }

  return charge > MAX_CHARGE ? MAX_CHARGE : charge;
}

int main(void) {
  const float firstHours = 1.50;
  const float secondHours = 4.00;
  const float thirdHours = 24.00;

  printf("%-6s\t%-6s\t%-6s\n", "Car", "Hours", "Charge");
  printf("%-6d\t%-6.2f\t%-6.2f\n", 1, firstHours, chargeParking(firstHours));
  printf("%-6d\t%-6.2f\t%-6.2f\n", 2, secondHours, chargeParking(secondHours));
  printf("%-6d\t%-6.2f\t%-6.2f\n", 3, thirdHours, chargeParking(thirdHours));
  printf("%-6s\t%-6.2f\t%-6.2f\n", "TOTAL", firstHours + secondHours + thirdHours, chargeParking(firstHours) + chargeParking(secondHours) + chargeParking(thirdHours));
}