// Kelvin Ton
#include <stdio.h>

int main()
{
  int change;
  printf("Please enter the amount of change (0-99): ");
  scanf("%d", &change);

  int quarters, dimes, nickels, pennies;
  quarters = change / 25;
  change = change - ( quarters * 25);

  dimes = change / 10;
  change = change - ( dimes * 10);

  nickels = change / 5;
  change = change - ( nickels * 5);

  pennies = change;

  printf("That would be %d quarters, %d dimes, %d nickels, and %d pennies.\n",
    quarters, dimes, nickels, pennies);

  return 0;
} //main();