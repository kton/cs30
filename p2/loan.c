// Kelvin Ton
#include <stdio.h>
#include <math.h>

void get_loan(double*amount, double*interest, int*months, int*payments);
void calc_payments(double amount, double interest, int months, int payments,
  double*payment_monthly, double*payment_sum);
void show_totals(double payment_monthly, double payment_sum);

int main()
{
  double amount = 0, interest = 0;
  int months = 0, payments = 0;

  get_loan(&amount, &interest, &months, &payments);

  double payment_sum = 0, payment_monthly = 0;

  calc_payments(amount, interest, months, payments, &payment_monthly,
    &payment_sum);
  
  show_totals(payment_monthly, payment_sum);

  return 0;
} //main();

void get_loan(double*amount, double*interest, int*months, int*payments)
{
  printf("Please enter the loan, and interest: ");
  scanf("%lf %lf", amount, interest);
  
  printf("Please enter the number of months until you start payments: ");
  scanf("%d", months);
  
  printf("Please enter the number of payments you wish to make: ");
  scanf("%d", payments);
} //get_loan();

void calc_payments(double amount, double interest, int months, int payments,
  double*payment_monthly, double*payment_sum)
{
  double years = 0, final_principal = 0;
  // a little extra work, but follows the formula given
  years = 1.0 * months / 12;
  final_principal = amount * pow(1 + interest / 12, 12 * years);
  
  double monthly_interest = 0;
  monthly_interest = interest / 12;

  *payment_monthly = (final_principal * monthly_interest) /
    ( 1 - exp(-1.0 * payments * log(1 + monthly_interest)));

  *payment_sum = *payment_monthly * payments;

  //instructions say to return the amount of monthly payments and total cost
} //calc_payments();

void show_totals(double payment_monthly, double payment_sum)
{
  printf("For that loan, your monthly payment will be $%0.2lf"
  ", for a total of $%0.2lf.\n", payment_monthly, payment_sum);
} //show_totals();