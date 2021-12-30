/* Exercise 05 from chapter 06.
 * Modify Program 5.9 so that it handles negative numbers correctly.
 */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int number, right_digit;
    bool isNegative;

    printf("Enter your number.\n");
    scanf("%i", &number);

    isNegative = number < 0;        // evaluate if the number is negative
    number *= 1 - (2 * isNegative); // if it is, negate it

    do {
        right_digit = number % 10;
        printf("%i", right_digit);
        number = number / 10;
    }
    while (number != 0);

    // if the number is negative, print a negative sign at the end
    isNegative ? printf("-\n") : printf("\n");

    return 0;
}

