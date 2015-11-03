// Kelvin Ton
#ifndef VECTOR_H
#define VECTOR_H
void initialize(int individual_count, int family_count,
  char ***indiIDs, char ***names, char ***spousesIDs, char ***childIDs);
void deallocate(int individual_count, int family_count,
  char **indiIDs, char **names, char **spousesIDs, char **childIDs);
#endif
#define INDI_LENGTH 20
#define SPOUSE_LENGTH 40