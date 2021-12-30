/* Exersice 02 from chapter 06.
 * Test two numbers to determine if the first is divisible by the second.
 */

#include <stdio.h>

int main(void)
{
    int a, b;

    printf("Please input two numbers: ");
    scanf("%i %i", &a, &b);

    if (a % b == 0)
        printf("%i IS divisible by %i\n", a, b);
    else
        printf("%i IS NOT divisible by %i\n", a, b);

    return 0;
}

