// Kelvin Ton
#include <stdio.h>
#define PI 3.14159265

int main()
{
  double diameter;
  printf("Please enter a diameter: ");
  scanf("%lf", &diameter);

  double circumference;
  circumference = PI * diameter;
  printf("The circumference of a circle with diameter %5.3lf is %5.2lf.\n",
    diameter, circumference);

  double area;
  area = PI * ( diameter / 2 ) * ( diameter / 2 );
  printf("The area of a circle with diameter %4.2lf is %6.3lf.\n",
    diameter, area);

  double surfacearea;
  surfacearea = 4 * PI * ( diameter / 2 ) * ( diameter / 2 );
  printf("The surface area of a sphere with diameter %7.5lf is %7.4lf.\n",
    diameter, surfacearea);

  double volume;
  volume = 4 / 3.0 * PI * ( diameter / 2 ) * ( diameter / 2 ) *
    ( diameter / 2 );
  printf("The volume of a sphere with diameter %6.4lf is %8.5lf.\n",
    diameter, volume);

  return 0;
} // main();