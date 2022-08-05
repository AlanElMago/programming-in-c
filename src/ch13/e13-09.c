/* Exercise 09 from chapter 13.
 * Write a macro ABSOLUTE_VALUE that computes the absolute value of its
 * argument.
 */

#define ABSOLUTE_VALUE(x) ( (x) < 0 ? -(x) : (x) )

#include <stdio.h>

int main(void)
{
    printf("ABSOLUTE_VALUE(1) = %i\n", ABSOLUTE_VALUE(1));
    printf("ABSOLUTE_VALUE(40 + 2) = %i\n", ABSOLUTE_VALUE(40 + 2));
    printf("ABSOLUTE_VALUE(-1) = %i\n", ABSOLUTE_VALUE(-1));
    printf("ABSOLUTE_VALUE(6 - 9) = %i\n", ABSOLUTE_VALUE(6 - 9));
    printf("ABSOLUTE_VALUE(0) = %i\n", ABSOLUTE_VALUE(0));

    return 0;
}
