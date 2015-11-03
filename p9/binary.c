// Kelvin Ton
#include <stdio.h>
#include <string.h>

void display(int pos, char input[]);

int main()
{
  char input[80];
  printf("Binary number: ");
  scanf("%s", input);
  input[strlen(input)+1] = '\0';
  display(0, input);
  
  return 0;
} // main()

void display(int pos, char input[])
{
  
  if (input[pos] == '\0') // base case
    printf("%s\n", input);
  else
  { // not end of string
    if(input[pos] == 'x')
    {
      input[pos] = '0';
      display(pos+1, input);
      input[pos] = '1';
      display(pos+1, input);
      input[pos] = 'x';
    }
    else // not x
      display(pos+1, input);
  } // end else
  
} // display()