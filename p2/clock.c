// Kelvin Ton
#include <stdio.h>
#include <stdlib.h>

void get_time(int*hours_a, int*mins_a, int*hours_b, int*mins_b);
void show_difference(int hours_a, int mins_a, int hours_b, int mins_b);

int main()
{
  int hours_a = 0, mins_a = 0, hours_b = 0, mins_b = 0;

  get_time(&hours_a, &mins_a, &hours_b, &mins_b);
  show_difference(hours_a, mins_a, hours_b, mins_b);

  return 0;
} //main();

void get_time(int*hours_a, int*mins_a, int*hours_b, int*mins_b)
{
  printf("Please enter time #1 in clock format: ");
  scanf("%d:%d", hours_a, mins_a);

  printf("Please enter time #2 in clock format: ");
  scanf("%d:%d", hours_b, mins_b);
} //get_time();

void show_difference(int hours_a, int mins_a, int hours_b, int mins_b)
{
  int time_a = 0, time_b = 0, time_diff = 0;
  //int diff_hours = 0, diff_mins = 0; //original - w/o signed zero

  //convert hours and minutes to strictly minutes
  time_a = hours_a * 60 + mins_a;
  time_b = hours_b * 60 + mins_b;
  
  time_diff = time_a - time_b;
  
  //diff_hours = time_diff / 60; //original - w/o
  int diff_mins = 0;
  diff_mins = abs(time_diff % 60);
  
  //printf("The difference is %d:%02d.\n", diff_hours, diff_mins); //original
  //%02.d - 02 is so that integer is padded to the second position with 0's
  
  //one point of extra credit
  //if you get 7:30 & 7:00 to display -0:30 instead of 0:30
  //use doubles to get a signed zero
  double diff_hours_signed = 0;
  diff_hours_signed = 1.0 * time_diff / 60;
  //dirty hack, takes advantage of rounding errors
  diff_hours_signed = diff_hours_signed - (0.5 * (time_diff % 60)/60 );

  printf("The difference is %0.0lf:%02d.\n", diff_hours_signed, diff_mins);
} //show_difference();