/* Exercise 08 from chapter 04.
 * Caluclates rounds an integer i to the next largest even multiple of another
 * integer j.
 *
 * Find the next largest even multiple of the following values of i and j:
 * i        j
 * 367      7
 * 12258   23
 * 996      4
 */

#include <stdio.h>

int main(void)
{
    int i, j, result;

    i = 367;
    j = 7;
    result = i + j - i % j;

    printf("The next largest multiple of %i of %i is %i\n", j, i, result);

    i = 12258;
    j = 23;
    result = i + j - i % j;

    printf("The next largest multiple of %i of %i is %i\n", j, i, result);

    i = 996;
    j = 4;
    result = i + j - i % j;

    printf("The next largest multiple of %i of %i is %i\n", j, i, result);

    return 0;
}

