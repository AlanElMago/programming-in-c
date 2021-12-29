/* Exercise 08 from chapter 05.
 * Modify Program 5.5 from chapter 05 so that the user can type the number of
 * triangular numbers to be calculated.
 */

#include <stdio.h>

int main(void)
{
    int n, number, triangularNumber, counter, upper_limit;

    printf("How many triangular numbers do you want to calculate? ");
    scanf("%i", &upper_limit);

    for (counter = 1; counter <= upper_limit; ++counter) {
        printf("\nWhat triangular number do you want? ");
        scanf("%i", &number);

        triangularNumber = 0;

        for (n = 1; n <= number; n = n + 1)
            triangularNumber += n;

        printf("The triangular number %i is %i\n\n", number, triangularNumber);
    }

    return 0;
}

