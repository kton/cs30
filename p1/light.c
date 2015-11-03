// Kelvin Ton
#include <stdio.h>
#define SPEED_LIGHT 299792458

int main()
{
  unsigned int cpufrequency;
  printf("Frequency of the CPU (Hz): ");
  scanf("%u", &cpufrequency);

  double distancepercpucycle;
  distancepercpucycle = 1.0 * SPEED_LIGHT / ( cpufrequency / 1000 );
  printf("Electricity can travel %.0lf millimeters in one cycle of a "
    "CPU that has\na frequency of %u Hz.\n",
    distancepercpucycle, cpufrequency);

  unsigned int distancepercpucycleusingintegers;
  distancepercpucycleusingintegers = SPEED_LIGHT / ( cpufrequency / 1000 );
  printf("Using only integers, that is %u millimeters.\n",
    distancepercpucycleusingintegers);

  return 0;
} //main();