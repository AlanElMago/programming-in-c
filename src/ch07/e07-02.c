/* Exercise 02 from chapter 07.
 * Modify Program 7.1 so that the elements of the array values are initially
 * set to 0.
 */

#include <stdio.h>

int main(void)
{
    int values[10] = {}; // all values in the array are to be initialized at 0
    int index;

    values[0] = 197;
    values[2] = -100;
    values[5] = 300;
    values[3] = values[0] + values[5];
    values[9] = values[5] / 10;
    --values[2];

    for (index = 0; index < 10; ++index)
        printf("values[%i] = %i\n", index, values[index]);

    return 0;
}

