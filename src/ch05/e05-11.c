/* Exercise 11 from chapter 05.
 * Calculate the sum of the digits of an integer.
 */

#include <stdio.h>

int main(void)
{
    int number;
    int sum_of_digits = 0;

    printf("Please input a positive integer: ");
    scanf("%i", &number);

    for (int magnitude = 1; magnitude < number; magnitude *= 10) {
        int digit = (number % (magnitude * 10)) / magnitude;
        sum_of_digits += digit;
    }

    printf("The sum of the digits of the number %i is %i\n",
            number, sum_of_digits);
}

