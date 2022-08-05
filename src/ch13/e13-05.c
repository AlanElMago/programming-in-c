/* Exercise 05 from chapter 13.
 * Write a macro SHIFT to perform the identical purpose as the shift function
 * of program 12.3.
 */

#define SHIFT(n, s) ( (s) > 0 ? (n) << (s) : (n) >> -(s) )

#include <stdio.h>

int main(void)
{
    printf("SHIFT(1024,  6): %i\n", SHIFT(1024,  6));
    printf("SHIFT(1024,  5): %i\n", SHIFT(1024,  5));
    printf("SHIFT(1024,  4): %i\n", SHIFT(1024,  4));
    printf("SHIFT(1024,  3): %i\n", SHIFT(1024,  3));
    printf("SHIFT(1024,  2): %i\n", SHIFT(1024,  2));
    printf("SHIFT(1024,  1): %i\n", SHIFT(1024,  1));
    printf("SHIFT(1024,  0): %i\n", SHIFT(1024,  0));
    printf("SHIFT(1024, -1): %i\n", SHIFT(1024, -1));
    printf("SHIFT(1024, -2): %i\n", SHIFT(1024, -2));
    printf("SHIFT(1024, -3): %i\n", SHIFT(1024, -3));
    printf("SHIFT(1024, -4): %i\n", SHIFT(1024, -4));
    printf("SHIFT(1024, -5): %i\n", SHIFT(1024, -5));
    printf("SHIFT(1024, -6): %i\n", SHIFT(1024, -6));

    return 0;
}
