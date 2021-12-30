/* Exercise 03 from chapter 06.
 * Display the result of dividing two integers to three-decimal-place accuracy.
 */

#include <stdio.h>

int main(void)
{
    int a, b;

    printf("Please input two numbers: ");
    scanf("%i %i", &a, &b);

    if (b == 0) {
        printf("Division by zero.\n");
        return 0;
    }

    float result = (float) a / b;

    printf("%i / %i = %.3f\n", a, b, result);

    return 0;
}

