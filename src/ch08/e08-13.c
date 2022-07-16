/* Exercise 13 from chapter 08.
 * Modify the sort function from Program 8.12 to take a third argument
 * indicating whether the array is to be sorted in asending or descending
 * order. Then modify the sort algorithm to correctly sort the array into the
 * indicated order.
 */

#include <stdio.h>

void sort (int a[], int n, int order)
{
    int i, j, temp;

    if (order == 0)
        for ( i = 0; i < n - 1; ++i )
            for ( j = i + 1; j < n; ++j )
                if ( a[i] > a[j] ) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
    
    if (order == 1)
        for ( i = 0; i < n - 1; ++i )
            for ( j = i + 1; j < n; ++j )
                if ( a[i] < a[j] ) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
}

int main (void)
{
    int i;
    int array1[16] = { 34, -5, 6, 0, 12, 100, 56, 22,
                      44, -3, -9, 12, 17, 22, 6, 11 };
    int array2[16] = { 34, -5, 6, 0, 12, 100, 56, 22,
                      44, -3, -9, 12, 17, 22, 6, 11 };

    void sort (int a[], int n, int order);

    printf ("The arrays before the sort:\n");

    printf ("array1: ");
    for ( i = 0; i < 16; ++i )
        printf ("%i ", array1[i]);

    printf ("\n");

    printf ("array2: ");
    for ( i = 0; i < 16; ++i )
        printf ("%i ", array2[i]);

    sort (array1, 16, 0);
    sort (array2, 16, 1);

    printf ("\n\nThe array after the sort:\n");

    printf ("array1: ");
    for ( i = 0; i < 16; ++i )
        printf ("%i ", array1[i]);

    printf("\n");

    printf ("array2: ");
    for ( i = 0; i < 16; i++ )
        printf ("%i ", array2[i]);

    printf ("\n");

    return 0;
}
