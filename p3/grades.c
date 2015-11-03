// Kelvin Ton
#include <stdio.h>

int main()
{
  int score;

  printf("Please enter a test score: ");
  scanf("%d", &score);
  
  switch (score / 10)
  {
    case 10 : printf("Letter grade: A\n"); break; // 100
    case 9 : printf("Letter grade: A\n"); break; // 90-99
    case 8 : printf("Letter grade: B\n"); break; // 80-89
    case 7 : printf("Letter grade: C\n"); break; // 70-79
    case 6 : printf("Letter grade: D\n"); break; // 60-69
    default : printf("Letter grade: F\n"); break; // anything else
  } //switch

  return 0;
} // main();