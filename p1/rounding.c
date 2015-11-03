// Kelvin Ton
#include <stdio.h>

int main()
{
  double roundinginput;
  printf("Please enter a monetary value: ");
  scanf("%lf", &roundinginput);

  roundinginput = roundinginput * 1000000;
  double result; //instructions say to do this
  result = roundinginput / 1000000;

  printf("%16.2lf\n", result);
  printf("%24.10lf\n", result);
  printf("%34.20lf\n", result);

  return 0;
} //main();