// Kelvin Ton
#ifndef SEARCH_H
#define	SEARCH_H

#include "main.h"
void find_children(char **indiIDs, char **names, char **spousesIDs, 
  char **childIDs, int individual_count, int family_count); 
 
int find_name(char name[80], char **names, int individual_count);
int find_ID(const char* ID, char **IDs, int count);
int individual_cmp(const void *ptr1, const void *ptr2);
#endif	

