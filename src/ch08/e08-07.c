/* Program 07 from Chapter 08.
 * Write a function that raises an integer to a pòsitive integer power.
 */

#include <stdio.h>

long x_to_the_n(int x, int n)
{
    long result = x;

    if (n < 0)
        return -1L;

    if (n == 0)
        return 1L;

    for (int i = 1; i < n; i++)
        result *= x;

    return result;
}

int main(void)
{
    printf("2⁰ = %li\n", x_to_the_n(2, 0));
    printf("2¹ = %li\n", x_to_the_n(2, 1));
    printf("2² = %li\n", x_to_the_n(2, 2));
    printf("2³ = %li\n", x_to_the_n(2, 3));
    printf("2⁴ = %li\n", x_to_the_n(2, 4));
    printf("2⁵ = %li\n", x_to_the_n(2, 5));
    printf("\n");

    printf("3⁰ = %li\n", x_to_the_n(3, 0));
    printf("3¹ = %li\n", x_to_the_n(3, 1));
    printf("3² = %li\n", x_to_the_n(3, 2));
    printf("3³ = %li\n", x_to_the_n(3, 3));
    printf("3⁴ = %li\n", x_to_the_n(3, 4));
    printf("3⁵ = %li\n", x_to_the_n(3, 5));
    printf("\n");

    printf("4⁰ = %li\n", x_to_the_n(4, 0));
    printf("4¹ = %li\n", x_to_the_n(4, 1));
    printf("4² = %li\n", x_to_the_n(4, 2));
    printf("4³ = %li\n", x_to_the_n(4, 3));
    printf("4⁴ = %li\n", x_to_the_n(4, 4));
    printf("4⁵ = %li\n", x_to_the_n(4, 5));
    printf("\n");

    printf("9⁹ = %li\n", x_to_the_n(9, 9));
}
