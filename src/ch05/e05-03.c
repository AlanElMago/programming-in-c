/* Exercise 03 from chapter 05.
 * Generate a table of triangle numbers using the formula n (n + 1) / 2.
 * Generate every fifth triangular number between 5 and 50.
 */

#include <stdio.h>

int main(void)
{
    int triangle_num;

    printf(" n    Triangle number n\n");

    for (int i = 5; i <= 50; i += 5) {
        triangle_num = i * (i + 1) / 2;
        printf(" %-2i   %-4i\n", i, triangle_num);
    }

    return 0;
}

