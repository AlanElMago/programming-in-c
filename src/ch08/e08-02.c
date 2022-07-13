/* Exercise 02 from chapter 08.
 * Modify Program 8.4 so that the value of triangularNumber is returned by the
 * function. Use the main function from program 5.5 so that it calls the
 * calculateTriangularNumber function.
 */

#include <stdio.h>

int calculateTriangularNumber (int n)
{
    int i, triangularNumber = 0;

    for ( i = 0; i <= n; ++i )
        triangularNumber += i;

    return triangularNumber;
}

int main (void)
{
    int n, number, triangularNumber, counter;

    for (counter = 1; counter <= 5; ++counter) {
        printf("What triangular number do you want? ");
        scanf("%i", &number);

        triangularNumber = calculateTriangularNumber(number);

        printf("The triangular number %i is %i\n\n", number, triangularNumber);
    }

    return 0;
}
