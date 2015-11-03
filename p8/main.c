// Kelvin Ton
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "vector.h"
#include "search.h"
#include "main.h"

int main(int argc, char **argv)
{
  char **indiIDs, **names, **spousesIDs, **childIDs;
  int individual_count, family_count;
  FILE *fp;
  Individual *individuals;
  Family *families;
  
  if(argc != 2)
  {
    printf("Usage: family.out <ged_filename>\n");
    return 1;
  } // if the number of arguments is wrong
  
  fp = count_records(argv[1], &individual_count, &family_count);
  initialize(&indiIDs, &names, &spousesIDs, &childIDs, individual_count,
    family_count, &individuals, &families);
  read_file(fp, individuals, families);
  
  qsort(individuals, individual_count, sizeof(Individual), individual_cmp);
  
  int i;
  for (i = 0; i < family_count; i++)
  {    
    printf("FAM: %s\n", families[i].FAM);
    printf("HUSB: %s\n", families[i].HUSB);
    printf("WIFE: %s\n", families[i].WIFE);
    printf("chil_count: %d\n", families[i].chil_count);
    int j;
    for (j = 0; j < families[i].chil_count; j++)
      printf("CHILs: %s\n", families[i].CHILs[j]);
  }
  /*for (i = 0; i < individual_count; i++)
  {    
    printf("INDI: %s\n", individuals[i].INDI);
    printf("NAME: %s\n", individuals[i].NAME);
    printf("FAMS: %s\n", individuals[i].FAMS);
    printf("FAMC: %s\n", individuals[i].FAMC);
  }*/
  find_children(indiIDs, names, spousesIDs, childIDs, individual_count, 
    family_count);
  deallocate(indiIDs, names, spousesIDs, childIDs, individual_count, 
    family_count);
  return 0;
} // main()

