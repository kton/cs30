// Kelvin Ton
#include <stdio.h>
#define POUNDTOKILO 0.453592
#define ARTIFICIALSUGARPERCENT 0.001

int main()
{
  double sweetener;
  printf("Amount of sweetener needed to kill the mouse (kg): ");
  scanf("%lf", &sweetener);

  double mouse;
  printf("Weight of the mouse (kg): ");
  scanf("%lf", &mouse);

  int dieter;
  printf("Goal weight of the dieter (pounds): ");
  scanf("%d", &dieter);

  double soda;
  soda = ( ( sweetener / ARTIFICIALSUGARPERCENT  ) / mouse )
    * ( dieter * POUNDTOKILO ) ;

  printf("For a goal weight of %d pounds, you may drink %.1lf kg of soda.\n",
   dieter, soda);
  
  return 0;
} // main();