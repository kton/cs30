// Kelvin Ton
#include <stdio.h>
#include "file.h"
#include "vector.h"
#include "search.h"

int main(int argc, char *argv[])
{
  char **indiIDs, **names, **spousesIDs, **childIDs;
  int individual_count, family_count;
  FILE *fp;
  
  if(argc != 2)
  {
    printf("Usage: family.out <ged_filename>\n");
    return 1;
  } // end if, # of arguments not = 2
  
  //printf("%d %s\n", argc, argv[1]);
  
  fp = count_records(argv[1], &individual_count, &family_count);
  
  //printf("(main.c) INDI: %d, FAM: %d\n", individual_count, family_count);
  
  initialize(individual_count, family_count, &indiIDs, &names, &spousesIDs, &childIDs);
  read_file(indiIDs, names, spousesIDs, childIDs, fp);
  find_children(individual_count, family_count, indiIDs, names, spousesIDs, childIDs);
  deallocate(individual_count, family_count, indiIDs, names, spousesIDs, childIDs);
  
  return 0;
} // main()