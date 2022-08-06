/* Exercise 01 from chapter 14.
 * Define a type FunctionPtr (using typedef) that represents a pointer to a
 * function that returns an int and that takes no arguments.
 */

#include <stdio.h>

int return_one(void);

typedef int (*FunctionPtr) (void);

int main()
{
    FunctionPtr func_ptr = return_one;

    printf("%i\n", (*func_ptr)());

    return 0;
}

int return_one(void)
{
    return 1;
}
