// Kelvin Ton
#include <stdio.h>

int is_prime(int number);

int main()
{
  int num1, num2;

  // do-while loop that asks for new pairs
  do // if nums not greater than one or in ascending order
  {
    printf("Please enter two integers greater than one, "
      "and in ascending order: ");
    scanf("%d %d", &num1, &num2);

    if((num1 < 2) || (num2 < 2) || (num1 >= num2))
    {
      
      if(num1 < 2 || num2 < 2) // nums must be greater than one
      {
        printf("The numbers must both be greater than one.\n");
      }
      else // num1 is greater than num2
      {
        printf("The numbers must be in ascending order.\n");
      }
      printf("Please try again.\n"); // This can only be used once.
      printf("\n");
      
    } //endif
    
  } while ((num1 < 2) || (num2 < 2) || (num1 >= num2));

  // initialize i for the upcoming loop
  int number = num1;

  // loop that prints out primes
  while (number <= num2)
  {
    
    if(is_prime(number))
    {
      printf("%d ",number);
    } //end if
    
    number++;
  } // end while

  printf("\n");

  return 0;
} // main();

int is_prime(int number)
{
  int divisor = 2, isprime = 1;
  
  while (divisor < number)
  {
    
    if((number % divisor) == 0)
      isprime = 0;
   
    divisor++;
  } // end while

  if (isprime == 1)
    return 1;
  else
    return 0;
    
} // is_prime();