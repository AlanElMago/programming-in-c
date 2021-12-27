/* Exercise 04 from chapter 04.
 * Converts fahrenheit to celsius.
 */

#include <stdio.h>

int main(void)
{
    // this can be modified to any floating point number
    float fahrenheit = 20.5f;

    // formula to convert fahrenhiet to celsius
    float celsius = (fahrenheit - 32) / 1.8f;

    printf("%g°F = %g°C\n", fahrenheit, celsius);

    return 0;
}

