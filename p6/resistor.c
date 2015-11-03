// Kelvin Ton
#include <stdio.h>
#include <string.h>
#include <math.h>

int search(char **list, int size, char *target);

int main()
{
  char *list[10] = {
    "black", "brown", "red", "orange", "yellow",
    "green", "blue", "violet", "gray", "white"
  }; // list, in order
  
  char another;
  do
  {
    printf("Enter the colors of the resistor's three bands, beginning with\n"
      "the band nearest the end.  Type the colors in lower case letters\n"
      "only, NO CAPS.\n");
    
    char band1[7], band2[7], band3[7];
    
    printf("Band 1 => ");
    scanf("%s", band1);
    
    printf("Band 2 => ");
    scanf("%s", band2);
    
    printf("Band 3 => ");
    scanf("%s", band3);

    int one = search(list, 10, band1);
    int two = search(list, 10, band2);
    int three = search(list, 10, band3);

    if(one > -1 && two > -1 && three > -1)
    {
      int resistance = 10 * one;
      resistance = resistance + two;
      resistance = resistance * pow(10, three) / 1000;
      printf("Resistance value:  %d kilo-ohms\n", resistance);
    } //endif all matched
    else if (one < 0) // band 1 doesn't match
      printf("Invalid color: %s\n", band1);
    else if (two < 0) // band 2 doesn't match
      printf("Invalid color: %s\n", band2);
    else // three < 0 aka band 3 doesn't match
      printf("Invalid color: %s\n", band3);
      
    printf("Do you want to decode another resistor?\n"
      "=> ");
    scanf("\n%c", &another);
  } while (another != 'n');

  return 0;
} // main();

int search(char **list, int size, char *target)
{
  int i;
  for (i = 0; i < size; i++)
    if (strcmp(list[i],target) == 0)
      return i;
  return -1;
} // search();
