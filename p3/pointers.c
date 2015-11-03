// Kelvin Ton
#include <stdio.h>

void operate(int*num, int*num2, int*num3);
int* read_address(int position);
int check_address(int*ptr, int*num_ptr, int*num2_ptr, int*num3_ptr);
int read_operand();
char read_operator();
void run_operation(int*ptr1, int*ptr2, int operand, char operator);

int main()
{
  int num, num2, num3;
  setvbuf(stdout, NULL, _IONBF, 0);
  printf("The addresses are num: %u, num2: %u, num3: %u\n",
    (unsigned) &num, (unsigned) &num2, (unsigned) &num3); // >80 length
  operate(&num, &num2, &num3);
  operate(&num, &num2, &num3);
  operate(&num, &num2, &num3);
  printf("Done\n");
  return 0;
} // main();

void operate(int*num, int*num2, int*num3) // NO printfs allowed here
{
  int *ptr1, *ptr2;
  
  if((ptr1 = read_address(1)) && check_address(ptr1, num, num2, num3)
    && (ptr2 = read_address(2)) && check_address(ptr2, num, num2, num3))
  {
    int operand = read_operand(); // read operand as int
    char operator = read_operator(); // read operator as char
    run_operation(ptr1, ptr2, operand, operator); // operate
  } // endif
  // done, thank god
} // operate();

int* read_address(int position)
{
  printf("Please enter int address #%d: ", position);
  
  int *ptr; //pointer to an integer
  scanf("%u", (unsigned*) &ptr); //read in an unsigned - want an address
  
  if (ptr == 0)
    ptr = ptr - 1;
  
  return ptr;
} // read_address();

int check_address(int*ptr, int*num_ptr, int*num2_ptr, int*num3_ptr)
{
  if (ptr == num_ptr||ptr == num2_ptr||ptr == num3_ptr)
  {
    printf("That is a valid address.\n");
    return 1; // returns false = continue
  }
  else // no match = not an address
  {
    printf("That is an invalid address.\n");
    return 0; // returns true = break
  }
} // check_address();

int read_operand()
{
  int operand;
  
  printf("Please enter an integer: ");
  scanf("%d", &operand);
  
  return operand;
} // read_operand();

char read_operator()
{
  char operator;
  
  printf("Please enter an operator: ");
  scanf("\n%c", &operator); // %c reads in whitespace

  return operator;
} // read_operator();

void run_operation(int*ptr1, int*ptr2, int operand, char operator)
{
  switch (operator)
  {
    case '+':
      *ptr2 = *ptr1 + operand;
      printf("First int: %d, second int: %d.\n", *ptr1, *ptr2);
      break;
    case '*':
      *ptr2 = *ptr1 * operand;
      printf("First int: %d, second int: %d.\n", *ptr1, *ptr2);
      break;
    case '=':
      *ptr1 = operand;
      *ptr2 = operand;
      printf("First int: %d, second int: %d.\n", *ptr1, *ptr2);
      break;
    case '%':
      *ptr2 = operand % *ptr1;
      printf("First int: %d, second int: %d.\n", *ptr1, *ptr2);
      break;
    default :
      printf("%c is an invalid operator.\n", operator);
      break;
  } // end switch
} // run_operation();