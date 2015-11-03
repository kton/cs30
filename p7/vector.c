// Kelvin Ton
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

void initialize(int individual_count, int family_count,
  char ***indiIDs, char ***names, char ***spousesIDs, char ***childIDs)
{
  //printf("(vector.c parameters) INDI: %d, FAM: %d\n", individual_count, family_count);
  
  *indiIDs = (char**) malloc(sizeof(char*) * individual_count);
  *names = (char**) malloc(sizeof(char*) * individual_count);
  *spousesIDs = (char**) malloc(sizeof(char*) * family_count);
  *childIDs = (char**) malloc(sizeof(char*) * family_count);
  
  int i;
  for (i = 0; i < individual_count; i++)
  {
    (*indiIDs)[i] = (char*) malloc(sizeof(char) * INDI_LENGTH);
    //(*names)[i] = (char*) malloc(sizeof(char) * INDI_LENGTH);
    (*names)[i] = NULL;
  } // end for indiIDs, names
  
  for (i = 0; i < family_count; i++)
  {
    (*spousesIDs)[i] = (char*) malloc(sizeof(char) * SPOUSE_LENGTH);
    (*spousesIDs)[i][0] = '\0';
    //(*childIDs)[i] = (char*) malloc(sizeof(char) * SPOUSE_LENGTH);
    (*childIDs)[i] = NULL;
  } // end for spousesIDs, childIDs
  
} // end initialize


void deallocate(int individual_count, int family_count,
  char **indiIDs, char **names, char **spousesIDs, char **childIDs)
{
  int i;
  for (i = 0; i < individual_count; i++)
  {
    if (indiIDs[i] != NULL)
      free(indiIDs[i]);
    if (names[i] != NULL)
      free(names[i]);
  } // end for indiIDs, names
  
  for (i = 0; i < family_count; i++)
  {
    if (spousesIDs[i] != NULL)
      free(spousesIDs[i]);
    if (childIDs[i] != NULL)
      free(childIDs[i]);
  } // end for spousesIDs, childIDs
  
  free(indiIDs);
  free(names);
  free(spousesIDs);
  free(childIDs);

} // end deallocate