/* Exercise 02 from chapter 05.
 * Generate and display a table of n and n² for integer values of n ranging
 * from 1 to 10.
 */

#include <stdio.h>

int main(void)
{
    printf(" n    n²\n");

    for (int i = 1; i <= 10; i++) {
        printf(" %-2i   %-3i\n", i, i * i);
    }
}

