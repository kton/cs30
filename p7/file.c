// Kelvin Ton
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "file.h"

FILE *count_records(const char *filename, int *individual_count, int *family_count)
{
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL)
  {
    printf("Unable to read %s.\n", filename);
    exit(1);
  } // end if unable to read file
  else // file reads fine
  {
    char line[80];
    *individual_count = 0;
    *family_count = 0;
    while (fgets(line, 80, fp) != NULL)
    {
      if (line[0] == '0')
      {
        if (strstr(line, "INDI") != NULL)
          *individual_count = *individual_count + 1;
        if (strstr(line, "FAM") != NULL)
          *family_count = *family_count + 1;
      } // endif starts with 0
    }
    //printf("(file.c) INDI: %d, FAM: %d\n", *individual_count, *family_count);
  }
  
  rewind(fp);
  
  return fp;
} // end count_records

void read_file(char **indiIDs, char **names, char **spousesIDs, char **childIDs, FILE *fp)
{
  char line[80];
  char *read_test;
  int individual_count = 0, family_count = 0;
  fgets(line, 80, fp);
  while (read_test != NULL)
  {
    printf("%s", line);
    if(strstr(line, "INDI") != NULL)
      read_test = read_indi(line, fp, &individual_count, indiIDs, names);
    else if (strstr(line, "FAM") != NULL)
      read_test = read_family(line, fp, &family_count, spousesIDs, childIDs);
    else
      read_test = read_other(line, fp);
  }
  
  int i;
  for (i = 0; i < individual_count; i++)
  //for (i = 0; i < family_count; i++)
  {
    printf("(%d) indiIDs: %s names: %s\n", i, indiIDs[i], names[i]);
    //printf("(%d) childIDs: %s spousesIDs: %s\n", i, childIDs[i], spousesIDs[i]);
  }
  
} // end read_file

char *read_indi(char *line, FILE *fp, int *individual_count, char **indiIDs, char **names)
{
  //printf("read_indi\n");
  
  char *ptr = strrchr(line, '@');
  *ptr = '\0';
  ptr = strchr(line,'@');
  strcpy(indiIDs[*individual_count], ptr+1);
  
  char *read_test;
  while(read_test != NULL)
  {
    fgets(line, 80, fp);
    if (strstr(line, "NAME") != NULL)
    {
      char *ptr2 = strstr(line,"NAME") + 4;
      //printf(">>>%s<<<\n", ptr2); // prints out full name with \n at end
      
      char *tmp = strtok(ptr2, " /");
      //printf(">>>%s<<<\n", tmp);
      char *full_name = tmp;
      while(tmp != NULL)
      {
        tmp = strtok(NULL, " /\n");
        if (tmp != NULL)
        {
          if (strstr(tmp, ",") != NULL)
            sprintf(full_name, "%s%s", full_name, tmp);
          else
            sprintf(full_name, "%s %s", full_name, tmp);
        }
        //printf(">>>%s<<<\n", tmp);
      }
      //printf(">>>%s<<<\n", full_name); // OK!
      //char *final_name = (char*) malloc((strlen(name) * sizeof(char*)));
      names[*individual_count] = (char*) malloc(((strlen(full_name)+1) * sizeof(char*)));
      strcpy(names[*individual_count], full_name);
      *individual_count = *individual_count + 1;
      
      //read_test = NULL;
      
      return line;
    }
    if (line == NULL)
      read_test = NULL;
  }
  return NULL;
} // end read_indi

char *read_family(char *line, FILE *fp, int *family_count, char **spousesIDs, char **childIDs)
{
  printf("read_family\n");
  
  // infinite loop
  /*
  char *read_test;
  while(read_test != NULL)
  {
    fgets(line, 80, fp);
    if (strstr(line, "HUSB") != NULL || strstr(line, "WIFE") != NULL)
    {
      char *ptr = strrchr(line, '@');
      *ptr = '\0';
      ptr = strchr(line,'@');
      sprintf(spousesIDs[*family_count], "%s %s", spousesIDs[*family_count], ptr+1);
      
      return line;
    }
    
    if (strstr(line, "CHIL") != NULL)
    {
      char *ptr = strrchr(line, '@');
      *ptr = '\0';
      ptr = strchr(line,'@');
      
      if (childIDs[*family_count] == NULL)
      {
        childIDs[*family_count] = (char*) malloc(((strlen(ptr)+1) * sizeof(char*)));
        strcpy(childIDs[*family_count], ptr);
      }
      else 
      {
        char *temp = (char*) malloc((strlen(childIDs[*family_count])+strlen(ptr)+1) * sizeof(char*));
        sprintf(temp, "%s %s", childIDs[*family_count], temp);
        free(childIDs[*family_count]);
        childIDs[*family_count] = temp;
      }
      *family_count = *family_count + 1;

      return line;
    }
    
    if (line == NULL)
      read_test = NULL;
  } */ 

  return NULL;
} // end read_family

char *read_other(char *line, FILE *fp)
{
  printf("read_other\n");
  char *read_test;
  while(read_test != NULL)
  {
    fgets(line, 80, fp);
    if (line[0] == '0')
    {
      //read_test = NULL;
      return line;
    }
    if (line == NULL)
      read_test = NULL;
  }
  return NULL;
} // end read_other