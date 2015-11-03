// Kelvin Ton
#ifndef MAIN_H
#define	MAIN_H

typedef struct
{
  char *INDI;
  char *NAME;
  char *FAMC;
  char *FAMS;
} Individual;

typedef struct
{
  char *FAM;
  char *HUSB;
  char *WIFE;
  int chil_count;
  char **CHILs;
} Family;

#endif	
