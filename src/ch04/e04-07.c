/* Exercise 07 from chapter 04.
 * Evaluate the following expression:
 * (3.31 x 10⁻⁸ x 2.01 x 10⁻⁷) / (7.16 x 10⁻⁶ + 2.01 x 10⁻⁸)
 */

#include <stdio.h>

int main(void)
{
    double a = 3.31e-8;
    double b = 2.01e-7;
    double c = 7.16e-6;
    double d = 2.01e-8;

    // the expression is simplified with variables
    double result = (a * b) / (c + d);

    printf("(3.31 x 10⁻⁸ x 2.01 x 10⁻⁷) / (7.16 x 10⁻⁶ + 2.01 x 10⁻⁸) = ");
    printf("%g\n", result);
}

