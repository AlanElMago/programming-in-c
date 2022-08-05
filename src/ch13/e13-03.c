/* Exercise 03 from chapter 13.
 * Define a macro MIN that gives the minimum of two values. Then write a
 * program to test the macro definition.
 */

#define MIN(a, b) ( (a) < (b) ? (a) : (b) )

#include <stdio.h>

int main(void)
{
    printf("MIN(52, 104): %i\n", MIN(52, 104));
    printf("MIN(420, 42): %i\n", MIN(420, 42));

    return 0;
}
