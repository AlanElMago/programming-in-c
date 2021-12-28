/* Exercise 04 from chapter 05.
 * Generate and print a table of the first 10 factorials.
 */

#include <stdio.h>

int main(void)
{
    printf(" n    n!\n");

    for (int i = 1; i <= 10; i++) {
        int factorial = 1;

        for (int j = 1; j <= i; j++) {
            factorial *= j;
        }

        printf(" %-2i   %-4i\n", i, factorial);
    }
}

