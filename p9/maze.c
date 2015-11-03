// Kelvin Ton
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FAIL 0
#define SUCCESS 1 

void read_file(char ***maze, char **argv);
void print_maze(char **maze);
int find_path(char **maze, int row, int col);

int main(int argc, char **argv)
{
  char **maze;
  read_file(&maze, argv);
  // uncomment print_maze to make grading easier ;)
  //print_maze(maze);
  //printf("\nfind_path:\n");
  if (find_path(maze, 7, 7) == FAIL)
    printf("No path was found.\n");
  //print_maze(maze);
  
  return 0;
} // main()

int find_path(char **maze, int row, int col)
{
  
  if (row < 0 || row > 7 || col < 0 || row > 7)
    return FAIL; // bad row or col, outside maze

  if (maze[row][col] == 'O' && (col == 1) && (row == 0)) // reached goal
  {
    printf("(%d, %d)\n", row, col);
    return SUCCESS;
  } // end if, reached goal
  
  if (maze[row][col] == 'X')
    return FAIL; // not on the path
    
  // end base case checks
  
  maze[row][col] = 'X'; // avoids an infinite loop
  
  if(row > 0 && find_path(maze, row-1, col)) // go_up
  {
    printf("(%d, %d)\n", row, col);
    //find_path(maze, row-1, col);
    return SUCCESS;
  } // endif
  
  if(col < 7 && find_path(maze, row, col+1)) // go_right
  {
    printf("(%d, %d)\n", row, col);
    //find_path(maze, row, col+1);
    return SUCCESS;
  } // endif
  
  if(row < 7 && find_path(maze, row+1, col)) // go_down
  {
    printf("(%d, %d)\n", row, col);
    //find_path(maze, row+1, col);
    return SUCCESS;
  } // endif
  
  if(col > 0 && find_path(maze, row, col-1)) // go_left
  {
    printf("(%d, %d)\n", row, col);
    //find_path(maze, row, col-1);
    return SUCCESS;
  } // endif
  
  return FAIL;
  
} // find_path()

void read_file(char ***maze, char **argv)
{
  *maze = (char**) malloc(8 * sizeof(char*)); // allocate rows
  
  int i;
  for (i = 0; i < 8; i++) // 8 chars + \0 at end
    (*maze)[i] = (char*) malloc(9 * sizeof(char)); // allocate columns
  
  //printf("%s", argv[1]); // debug: prints filename
  FILE *fp = fopen(argv[1], "r"); // open file
  
  for (i = 0; i < 8; i++) // eight rows
    fscanf(fp, "%s", (*maze)[i]);
      
  fclose(fp);
} // read_file()

void print_maze(char **maze)
{
  printf("\nprint_maze:\n");
  int i, j;
  for (i = 0; i < 8; i++)
  {
    for (j = 0; j < 8; j++)
      printf("%c", maze[i][j]); // print col
    printf("\n");
  } // end printrows
} // print_maze()