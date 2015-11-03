// Kelvin Ton
#include <stdio.h>

void tens(int number);
void ones(int number);
void teens(int number);

int main()
{
  int number;
  printf("Please enter a number between 0 and 99: ");
  scanf("%d", &number);
  
  printf("In English, that is ");
  
  if (number >= 20) // less or equal to 20
  {
    tens(number);
    ones(number);
  } // endif num 20+
  
  if (number < 20) // less than 20
    teens(number);
  
  printf(".\n");
  return 0;
  
} // main();

void tens(int number)
{
  switch (number / 10)
  {
    case 9 : printf("ninety"); break;
    case 8 : printf("eighty"); break;
    case 7 : printf("seventy"); break;
    case 6 : printf("sixty"); break;
    case 5 : printf("fifty"); break;
    case 4 : printf("forty"); break;
    case 3 : printf("thirty"); break;
    case 2 : printf("twenty"); break;
    default : break; // case 1 should not exist
  } // switch
} // tens();

void ones(int number)
{
  switch (number % 10)
  {
    case 9 : printf("-nine"); break;
    case 8 : printf("-eight"); break;
    case 7 : printf("-seven"); break;
    case 6 : printf("-six"); break;
    case 5 : printf("-five"); break;
    case 4 : printf("-four"); break;
    case 3 : printf("-three"); break;
    case 2 : printf("-two"); break;
    case 1 : printf("-one"); break;
    default : break; // zeroes
  } // switch
} // ones();

void teens(int number)
{
  switch (number / 1)
  {
    case 19 : printf("nineteen"); break;
    case 18 : printf("eighteen"); break;
    case 17 : printf("seventeen"); break;
    case 16 : printf("sixteen"); break;
    case 15 : printf("fifteen"); break;
    case 14 : printf("fourteen"); break;
    case 13 : printf("thirteen"); break;
    case 12 : printf("twelve"); break;
    case 11 : printf("eleven"); break;
    case 10 : printf("ten"); break;
    case 9 : printf("nine"); break;
    case 8 : printf("eight"); break;
    case 7 : printf("seven"); break;
    case 6 : printf("six"); break;
    case 5 : printf("five"); break;
    case 4 : printf("four"); break;
    case 3 : printf("three"); break;
    case 2 : printf("two"); break;
    case 1 : printf("one"); break;
    case 0 : printf("zero"); break;
    default : break; // out of range
  } // switch
} // teens();