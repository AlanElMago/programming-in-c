/* Exercise 04 from chapter 07.
 * Calculate the average of an array of 10 floating-point values.
 */

#include <stdio.h>

int main(void)
{
    float values[10] = {};
    float sum = 0.0f, average = 0.0f;

    printf("Enter 10 floating-point numbers.\n");

    // input the values of the array
    for (int i = 0; i < 10; i++) {
        printf("values[%i] = ", i);
        scanf("%f", &values[i]);
    }

    // caluclate the average of the array
    for (int i = 0; i < 10; i++)
        sum += values[i];

    average = sum / 10.0f;

    printf("\nThe average of the array is: %f\n", average);

    return 0;
}
