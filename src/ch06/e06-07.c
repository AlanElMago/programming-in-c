/* Exercise 07 from chapter 06.
 * Modify Program 6.10 and include the following optimizations:
 *      1. Skip all the even numbers in the inner for loop.
 *      2. Break the inner for loop if the tested number is not prime.
 */

#include <stdio.h>

int main(void)
{
    int p, d;
    _Bool isPrime;

    for (p = 2; p <= 50; ++p) {
        isPrime = 1;

        for (d = 3; d < p; d += 2)
            if (p % d == 0) {
                isPrime = 0;
                break;
            }

        if (isPrime != 0)
            printf("%i ", p);
    }

    printf("\n");

    return 0;
}

