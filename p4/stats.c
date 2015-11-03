// Kelvin Ton
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE *read_file(double *average, int *position);
void print_stats(int minimum, int maximum, int total, int per_line);
void print_stddev(double *average, int *position, FILE *data);

int main()
{
  
  FILE *data;
  double average;
  int position;
  data = read_file(&average, &position);
  print_stddev(&average, &position, data);
  
  return 0;
} // main();

FILE *read_file(double *average, int *position)
{
  FILE *data;
  data = fopen("stats_data.txt", "r");

  int per_line;
  fscanf(data,"%d",&per_line);

  int num, pos = 1;
  int minimum, maximum, total, abs_total;
  
  while(fscanf(data, "%d", &num) != EOF)
  {
    if (pos % (2 * per_line + 1) == 0)
      printf("\n");

    if (((pos - 1) % per_line) == 0)
      minimum = maximum = total = num;
      
    if (num < minimum)
      minimum = num;

    if (num > maximum)
      maximum = num;

    if (((pos - 1) % per_line) != 0)
      total = total + num;

    if (pos % per_line == 0)
      print_stats(minimum, maximum, total, per_line);

    if (pos == 1)
      abs_total = num + per_line;

    if (pos != 1)
      abs_total = abs_total + num;
    
    pos++;
  } // endwhile
  
  printf("\n");

  *average = (1.0 * abs_total) / pos;
  *position = pos;
  printf("Average: %.2lf ", *average);
  return(data);
  
} // read_file();

void print_stats(int minimum, int maximum, int total, int per_line)
{
  double average;
  average = 1.0 * total / per_line;
  printf("min: %-3d max: %-3d avg: %-6.2lf ", minimum, maximum, average);
} // print_stats();

void print_stddev(double *average, int *position, FILE *data)
{
  rewind(data);

  int columns;
  fscanf(data,"%d", &columns);
  
  double sum;
  sum = 1.0 * (columns - *average) * (columns - *average);

  int num;

  while(fscanf(data, "%d", &num) != EOF)
  {
    sum = sum + ((num - *average) * (num - *average));
  } // endwhile

  double stddev;
  stddev = sqrt(sum / (*position - 1));
  
  printf("Standard deviation: %.2lf\n", stddev);
} // print_stddev();