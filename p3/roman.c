// Kelvin Ton
#include <stdio.h>

int main()
{
  int input;
  printf("Please enter a number between 1 and 3999: ");
  scanf("%d", &input);
  
  printf("In Roman numerals that is ");
  
  switch (input / 1000)
  {
    case 3 : printf("MMM"); input -= 3000; break;
    case 2 : printf("MM"); input -= 2000; break;
    case 1 : printf("M"); input -= 1000; break;
    default : break;
  } // switch 1000's

  switch (input / 100)
  {
    case 9: printf("CM"); input -= 900; break;
    case 8: printf("DCCC"); input -= 800; break;
    case 7: printf("DCC"); input -= 700; break;
    case 6: printf("DC"); input -= 600; break;
    case 5: printf("D"); input -= 500; break;
    case 4: printf("CD"); input -= 400; break;
    case 3: printf("CCC"); input -= 300; break;
    case 2: printf("CC"); input -= 200; break;
    case 1: printf("C"); input -= 100; break;
    default : break;
  } // switch 100's
  
  switch (input / 10)
  {
    case 9: printf("XC"); input -= 90; break;
    case 8: printf("LXXX"); input -= 80; break;
    case 7: printf("LXX"); input -= 70; break;
    case 6: printf("LX"); input -= 60; break;
    case 5: printf("L"); input -= 50; break;
    case 4: printf("XL"); input -= 40; break;
    case 3: printf("XXX"); input -= 30; break;
    case 2: printf("XX"); input -= 20; break;
    case 1: printf("X"); input -= 10; break;
    default : break;
  } // switch 10's
  
  switch (input / 1)
  {
    case 9: printf("IX"); input -= 9; break;
    case 8: printf("VII"); input -= 8; break;
    case 7: printf("VII"); input -= 7; break;
    case 6: printf("VI"); input -= 6; break;
    case 5: printf("V"); input -= 6; break;
    case 4: printf("IV"); input -= 4; break;
    case 3: printf("III"); input -= 3; break;
    case 2: printf("II"); input -= 2; break;
    case 1: printf("I"); input -= 1; break;
    default : break;
  } // switch 1's
  
  printf(".\n"); //newline to match output

  return 0;
} // main();