// Kelvin Ton
#include <stdio.h>

int main()
{
  int velocity;
  
  printf("Please enter the wind velocity in knots: ");
  scanf("%d",&velocity);
  
  // Can only use if statements
  // more than one may execute, if not properly specified
  if (velocity < 1)
    printf("That is calm.\n"); // less than 1 knot
  
  if (velocity >= 1 && velocity <=3)
    printf("That is light air.\n"); // 1-3 knots
  
  if (velocity >= 4 && velocity <=27)
    printf("That is a breeze.\n"); // 4-27 knots
  
  if (velocity >= 28 && velocity <=47)
    printf("That is a gale.\n"); // 28-47 knots
  
  if (velocity >= 48 && velocity <= 63)
    printf("That is a storm.\n"); // 48-63 knots
  
  if (velocity > 63)
    printf("That is a hurricane.\n"); // more than 63 knots
  
  return 0;
} // main();