// Kelvin Ton
#include <stdio.h>

int main()
{
  double income, tax;

  printf("Please enter your gross taxable_income for 2012: ");
  scanf("%lf",&income);

  // remember that taxable income = gross - 5950
  income = income - 5950;

  if (income <= 0)
    tax = 0.00;
  else // greater than 5950

    if (income <= 8700)
      tax = 0.1 * (income);
    else // greater than 8700

      if (income <= 35350)
        tax = 870.0 + 0.15 * (income - 8700);
      else // greater than 35350

        if (income <= 85650)
          tax = 4867.50 + 0.25 * (income - 35350);
        else // greater than 85650

          if (income <= 178650)
            tax = 17422.50 + 0.28 * (income - 85650);
          else // greater than 178650

            if (income <= 388350)
              tax = 43482.50 + 0.33 * (income - 178650);
            else // greater than 388350

                tax = 112683.50 + 0.35 * (income - 388350);
                // end

    // restore original income amount to print out
    income = income + 5950;

  // print tax
  printf("The tax on $%0.2lf is $%0.2lf.\n", income, tax);

  return 0;
} // main();