// Kelvin Ton
#include <stdio.h>

void insertion_sort(int index, int sort[20]);
void binary_search(int index, int sort[20]);

int main()
{
  FILE *data;
  data = fopen("data.txt", "r");
  int sort[20], index = 0, num;
  
  while(fscanf(data, "%d", &num) != EOF)
  {
    sort[index] = num;
    index++;
  } // end while
  
  insertion_sort(index, sort);
  binary_search(index, sort);
  
  return 0;
} // main();

void insertion_sort(int index, int sort[20])
{
  int i, j, k, num;
  
  for(i = 1; i < index; i++)
  {
    num = sort[i];
    
    for(j = i - 1; j >= 0 && sort[j] > num; j--)
      sort[j + 1] = sort[j];
    
    sort[j + 1] = num;
    
    printf("Pass %2d: ", i);
    
    for(k = 0; k < index; k++)
      printf("%3d ", sort[k]);
    
    printf("\n");
  } // end for
  
  printf("\n");
  
} // insertion_sort();

void binary_search(int index, int sort[20])
{

  int key;
  
  do
  {
    int low = 0;
    int high = index;
    int mid = (low + high) / 2;
    
    printf("Please enter a value (-1 = done)> ");
    scanf("%d", &key);
    
    do // binary search algorithm
    {
      
      if (sort[mid] != key) // don't screw it up, if mid = key!
      {
        if (sort[mid] > key) // element is greater than key
          high = mid - 1;
        else // element is less than key
          low = mid + 1;
        mid = (low + high) / 2; // set the middle
      } // endif
      
    } while (low < high && sort[mid] != key);
    
    if (sort[mid] == key)
      printf("%d is located at position %d in the array.\n\n", key, mid);
    
    if (sort[mid] != key && key != -1)
      printf("%d is not in the array.\n\n", key);

  } while (key != -1);

} // binary_search();