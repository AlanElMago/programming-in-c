/* Exercise 8 from chapter 11.
 * Write a function called sort3 to sort three integers into ascending order.
 * (This function is not to be implemented with arrays.)
 */

#include<stdio.h>

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void sort3(int *a, int *b, int *c)
{
    if (*a > *b)
        swap(a, b);

    if (*a > *c)
        swap(a, c);

    if (*b > *c)
        swap(b, c);
}

int main(void)
{
    int a = 7, b = 11, c = 3;

    printf("a = %i, b = %i, c = %i\n\n", a, b, c);

    printf("Sorting a, b and c into ascending order...\n\n");
    sort3(&a, &b, &c);

    printf("a = %i, b = %i, c = %i\n\n", a, b, c);

    return 0;
}
