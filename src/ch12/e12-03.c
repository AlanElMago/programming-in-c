/* Exercise 03 from chapter 12.
 * Write a function called int_size that returns the number of bits contained
 * in an int on your particular machine.
 */

#include <stdio.h>

int int_size(void)
{
    unsigned int n = ~0;
    int bytes = 0;

    while ( n > 0 ) {
        n >>= 8;
        bytes++;
    }

    return bytes * 8;
}

int main(void)
{
    printf("Your computer has an int size of %i bits.\n", int_size());

    return 0;
}
