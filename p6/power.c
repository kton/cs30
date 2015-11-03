// Kelvin Ton
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_grid(int **grid);
void display_grid(int **grid);
int power_ok(int **grid);
void where_off(int **grid);

int main()
{
  int **grid = (int**) malloc(3*sizeof(int*));
  
  int i;
  for (i = 0; i < 4; i++)
    grid[i] = (int*) malloc(4*sizeof(int));

  get_grid(grid);
  display_grid(grid);
  
  if (power_ok(grid))
    printf("Power is on throughout grid.\n");
  else
    where_off(grid);
    
  return 0;
} // main();

void get_grid(int **grid)
{
  printf("Filename: ");
  char filename[20];
  scanf("%s", filename);
  
  FILE *data;
  data = fopen(filename, "r");
  
  int num, i = 0, j = 0;
  while(fscanf(data, "%d", &num) != EOF)
  {
    grid[i][j] = num;
    j++;
    
    if(j == 4) //hop over to next
    {
      i++;
      j = 0;
    } // endif

  } // end while
  
  fclose(data); // done reading
} // get_grid();

void display_grid(int **grid)
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 4; j++)
    {
      printf("%d ", grid[i][j]);
    } // end for, inner
    printf("\n");
  } // end for, outer
  printf("\n"); // done printing
} // display_grid();

int power_ok(int **grid)
{
  int status = 1;
  
  int i, j;
  for (i = 0; i < 3; i++)
    for (j = 0; j < 4; j++)
      if (!grid[i][j])
        status = 0;

  return status;
} // power_ok();

void where_off(int **grid)
{
  printf("Power is off in sectors:\n");
  
  int i, j;
  for (i = 0; i < 3; i++)
    for (j = 0; j < 4; j++)
      if (!grid[i][j])
        printf("      (%d,%d)\n",i,j);
} // where_off();