/* Exercise 07 from chapter 07.
 * Finds all the prime numbers from 2 to 150 using the Sieve of Erastothenes
 * algorithm.
 */

#include <stdio.h>

int main(void)
{
    const int UPPER_LIMIT = 150;
    int primes_set[UPPER_LIMIT];

    // initialize all elements of the array primes_set to 0
    for (int i = 0; i < 150; i++)
        primes_set[i] = 0;

    // Sieve of Erastothenes algorithm
    for (int i = 2; i <= UPPER_LIMIT; i++) {
        if (primes_set[i] == 0)
            printf("%i ", i);

        for (int j = 2; j * i <= UPPER_LIMIT; j++)
            primes_set[j * i] = 1;
    }

    printf("\n");

    return 0;
}

