// Kelvin Ton
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char **resize(char** unique, int unique_size);
int search(char **list, int size, char *target);
void free_unique(char** unique, int unique_size);

int main()
{
  char filename[31];
  printf("Filename: ");
  scanf("%s", filename);
  
  FILE *data;
  data = fopen(filename, "r");
  
  char **unique = (char**) malloc(10*sizeof(char**));
  int total_words = 0, count = 0, unique_size = 10;
  // NOTE THAT count = unique_count, just following instructions!
  
  int length_count[30] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
  }; //length_count array
  
  char word[160], wordalpha[31];
  while(fscanf(data, "%s", word) != EOF)
  {
    int i = 0, k = 0, stop = 0;
    do
    {
      if (isalpha(word[i]))
      {
        wordalpha[k] = tolower(word[i]);
        k++;
      } //endif isalpha
      if (!isalpha(word[i]) && k > 0)
        stop = 1; // breaks the loop: non-alpha after alpha
      i++;
    } while (i < strlen(word) && !stop);
    
    wordalpha[k] = '\0'; // end the alpha-only string
    
    if (k > 0)
      total_words++; // increments total word count
    
    if (count == unique_size) // unique count = unique size
    {
      unique = resize(unique, unique_size);
      unique_size = unique_size * 2;
    } // endif resizing
    
    if (wordalpha[0] != '\0') // making sure it's a word
    {
      if (search(unique, count, wordalpha) > -1) // already in unique
        length_count[strlen(wordalpha)-1] =
          length_count[strlen(wordalpha)-1] + 1; // increment total
      else // new unique entry
      {
        unique[count] =
          (char*) malloc((strlen(wordalpha)+1)*sizeof(char));
        strcpy(unique[count],wordalpha);
        count++; // incrememnt unique count
        length_count[strlen(wordalpha)-1] =
          length_count[strlen(wordalpha)-1] + 1; // increment total
      } // end else
    } // endif unique processing
    
  } // end while fscanf
  
  printf("Total words: %d  Unique words: %d  Unique's size: %d\n",
    total_words, count, unique_size);
  
  printf("Length Count\n");
  int i;
  for (i = 0; i < 30; i++)
  {
    if (length_count[i] > 0)
      printf("%4d   %4d\n", i+1, length_count[i]);
  } // end for length count printing
  
  free_unique(unique, unique_size); // free allocated memory
  
  return 0;
} // main();

int search(char **list, int size, char *target)
{ // very important to have the != NULL, otherwise SEGFAULT!
  int i;
  for (i = 0; i < size; i++)
    if (list[i] != '\0' && strcmp(list[i],target) == 0)
      return i;
  return -1;
} // search();

char **resize(char** unique, int unique_size)
{
  char **temp = (char**) malloc((2*unique_size)*sizeof(char**));
  int i;
  for (i=0; i <= unique_size; i++)
    temp[i] = unique[i];
  free(unique);
  return temp;
} // resize();

void free_unique(char** unique, int unique_size)
{
  int i;
  for (i=0; i <= unique_size; i++)
    free(unique[i]);
  free(unique);
} // free_unique();