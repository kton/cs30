// Kelvin Ton
#include <stdio.h>

void rectangle();
void head();
void triangle();
void blank_lines();
void lines();

int main()
{
  head();
  triangle();
  lines(); //end girl
  
  blank_lines();
  
  head();
  rectangle();
  lines(); //end boy
  
  blank_lines();
  
  triangle();
  rectangle();
  rectangle();
  lines(); //end rocket

  return 0;
} //main();

void rectangle()
{
  printf("|----|\n");
  printf("|    |\n");
  printf("|----|\n");
} //rectangle();

void head()
{
  printf(" /---\\\n");
  printf("| 0 0 |\n");
  printf(" \\_-_/\n");
} //head();

void lines()
{
  printf("  /\\\n");
  printf(" /  \\\n");
  printf("/    \\\n");
} //triangle();

void blank_lines()
{
  printf("\n");
  printf("\n");
} //blank_lines();

void triangle()
{
  printf("  /\\\n");
  printf(" /  \\\n");
  printf("/____\\\n");
} //legs();