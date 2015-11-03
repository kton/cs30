// Kelvin Ton
#include <stdio.h>

void get_grades(const char*course, int*tot_a, int*tot_b, int*tot_c,
  int*tot_d, int*tot_f);
void show_totals(int tot_a, int tot_b, int tot_c, int tot_d, int tot_f);

int main()
{
  int tot_a = 0, tot_b = 0, tot_c = 0, tot_d = 0, tot_f = 0;
  
  get_grades("ECS 10", &tot_a, &tot_b, &tot_c, &tot_d, &tot_f);
  get_grades("ECS 20", &tot_a, &tot_b, &tot_c, &tot_d, &tot_f);
  get_grades("ECS 30", &tot_a, &tot_b, &tot_c, &tot_d, &tot_f);
  get_grades("ECS 40", &tot_a, &tot_b, &tot_c, &tot_d, &tot_f);
  
  show_totals(tot_a, tot_b, tot_c, tot_d, tot_f);
  
  return 0;
} //main();

void get_grades(const char*course, int*tot_a, int*tot_b, int*tot_c,
  int*tot_d, int*tot_f)
{
  int count_a = 0, count_b = 0, count_c = 0, count_d = 0, count_f = 0;
  printf("Please enter the grades for %s in order As Bs Cs Ds Fs: ", course);
  scanf("%d %d %d %d %d", &count_a, &count_b, &count_c, &count_d, &count_f);
  
  *tot_a = *tot_a + count_a;
  *tot_b = *tot_b + count_b;
  *tot_c = *tot_c + count_c;
  *tot_d = *tot_d + count_d;
  *tot_f = *tot_f + count_f;
} //get_grades();

void show_totals(int tot_a, int tot_b, int tot_c, int tot_d, int tot_f)
{
  int tot_count = 0;
  int pct_a = 0, pct_b = 0, pct_c = 0, pct_d = 0, pct_f = 0;

  tot_count = tot_a + tot_b + tot_c + tot_d + tot_f;

  pct_a = 100 * tot_a / tot_count;
  pct_b = 100 * tot_b / tot_count;
  pct_c = 100 * tot_c / tot_count;
  pct_d = 100 * tot_d / tot_count;
  pct_f = 100 * tot_f / tot_count;
  
  printf("The percentages were A: %d%%, B: %d%%, C: %d%%, D: %d%%, F: %d%%.\n",
    pct_a, pct_b, pct_c, pct_d, pct_f);
} //show_totals();