// Kelvin Ton
#ifndef FILE_H
#define FILE_H
FILE *count_records(const char *filename, int *individual_count, int *family_count);
void read_file(char **indiIDs, char **names, char **spousesIDs, char **childIDs, FILE *fp);
char *read_indi(char *line, FILE *fp, int *individual_count, char **indiIDs, char **names);
char *read_family(char *line, FILE *fp, int *family_count, char **spousesIDs, char **childIDs);
char *read_other(char *line, FILE *fp);
char *get_ID(char *line);
#endif