// Kelvin Ton
#include <stdio.h>
#include <float.h>

double get_dbl(double d_max, double d_min);

int main()
{
  double d_max, d_min, input;
  d_max = DBL_MAX;
  d_min = -DBL_MAX;
  
  d_min = get_dbl(d_max, d_min);
  d_max = get_dbl(d_max, d_min);
  input = get_dbl(d_max, d_min);
  
  printf("min: %0.8g, max: %0.4g, input: %0.4g are all OK.\n",
    d_min, d_max, input);
  return 0;
  
} // main();

double get_dbl(double d_max, double d_min)
{
  int error;
  double input;
  char skip_ch;
  
  do
  {
    error = 0; // no error yet
    printf("Enter a double in the range from %0.8g to %0.8g inclusive> ",
      d_min, d_max);
    scanf("%lf", &input);
    scanf("%c", &skip_ch);
    
    if (skip_ch != '\n')
    {
      error = 1;
      printf("Invalid character >>%c>>. Skipping rest of line.\n", skip_ch);

      do
        scanf("%c", &skip_ch);
      while(skip_ch != '\n');
      
    } // end if invalid character
    else if(input < d_min || input > d_max)
    { // otherwise check if too big or small
      error = 1;
      if (input < d_min)
        printf("Number %0.8g is too small.\n", input);
      if (input > d_max)
        printf("Number %0.8g is too large.\n", input);
    } // end if num too big or small
      
  } while (error);
  
  return input;
} // get_dbl();