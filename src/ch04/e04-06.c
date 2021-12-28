/* Exercise 06 from chapter 04.
 * Evaluate the polynomial 3x³ - 5x² + 6 for x = 2.55.
 */

#include <stdio.h>

int main(void)
{
    double x = 2.55;

    // x³ = x * x * x and x² = x * x
    double result = (3 * x * x * x) - (5 * x * x) + 6;

    printf("f(x) = 3x³ - 5x² + 6\n");
    printf("f(%g) = %g\n", x, result);

    return 0;
}

