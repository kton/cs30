// Kelvin Ton
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "vector.h"
#include "search.h"
#include "main.h"

typedef enum { DONE, FIND, PRINT } Menu;
void run(int individual_count, int family_count, Individual *individuals,
  Family *families);

int main(int argc, char **argv)
{
  int individual_count, family_count;
  Individual *individuals;
  Family *families;
  
  FILE *fp;
  
  if(argc != 2)
  {
    printf("Usage: family.out <ged_filname>\n");
    return 1;
  } // if the number of arguments is wrong
  
  fp = count_records(argv[1], &individual_count, &family_count);
  initialize(individual_count, family_count, &individuals, &families);
  read_file(fp, individuals, families);
  qsort(individuals, individual_count, sizeof(Individual), individual_cmp);
  qsort(families, family_count, sizeof(Family), family_cmp);
  //find_children(individual_count, family_count, individuals, families);
  run(individual_count, family_count, individuals, families);
  deallocate(individual_count,family_count, individuals, families);
  return 0;
} // main()

void run(int individual_count, int family_count, Individual *individuals,
  Family *families)
{
  int choice;
  char garbage;
  do
  {
    printf("\nMenu\n"
    "0. Done\n"
    "1. Find children.\n"
    "2. Print family tree.\n"
    "Your choice: ");
    scanf("%d", &choice);
    if (choice == FIND)
    {
      scanf("%c", &garbage);
      //char name[80];
      //printf("Please enter a name: ");
      //fgets(name, 80, stdin);
      //int name_index;
      //name_index = find_name(name, individual_count, individuals);
      char *indi_id = NULL; // null to avoid warning
      //indi_id = individuals[name_index].INDI;
      find_children(individual_count, family_count, individuals, families, indi_id);
    }
    if (choice == PRINT)
    {
      scanf("%c", &garbage);
      printTree(individual_count, family_count, individuals, families);
    }
  } while(choice != DONE);
} // run()
