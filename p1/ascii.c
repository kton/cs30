// Kelvin Ton
#include <stdio.h>

int main()
{
  char character1, character2;
  int integer1;

  printf("Please enter two characters and an integer: ");
  scanf("%c%c%d", &character1, &character2, &integer1);
  
  char c1plusc2, c1minusc2, c1plusnum;
  c1plusc2 = character1 + character2;
  c1minusc2 = character1 - character2;
  c1plusnum = character1 + integer1;
  
  printf("c1 + c2 = %c (char), %d (int).\n", c1plusc2, c1plusc2);
  printf("c1 - c2 = %c (char), %d (int).\n", c1minusc2, c1minusc2);
  printf("c1 + num = %c (char), %d (int).\n", c1plusnum, c1plusnum);
  
  return 0;
} //main();