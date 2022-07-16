/* Exercise 11 from chapter 08.
 * Write a function called arraySum that takes two arguments: an integer array
 * and the number of elements in the array. Have the function return as its
 * result the sum of the elements of the array.
 */

#include <stdio.h>

int array_sum(int array_size, int array[array_size])
{
    int sum = 0;

    for (int i = 0; i < array_size; i++)
        sum += array[i];

    return sum;
}

int main(void)
{
    int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
                19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
                34, 35, 36};
    int a2[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
    int a3[] = {5, -2, 0, -6, 2};

    printf("Sum of a1 = %i\n", array_sum(36, a1));
    printf("Sum of a2 = %i\n", array_sum(16, a2));
    printf("Sum of a3 = %i\n", array_sum(5, a3));

    return 0;
}
