/* Exercise 06 from chapter 13.
 * Weite a macro IS_UPPER_CASE that gives a nonzero value if a character is an
 * uppercase letter.
 */

#define IS_UPPER_CASE(c) ( (c) >= 'A' && (c) <= 'Z' ? (c) : 0 )

#include <stdio.h>

int main(void)
{
    char *str = "Hello, World!";
    char *tmp = str;

    printf("%s\n\n", str);

    while ( *tmp != '\0' )
        printf("Is %c an uppercase letter? %s\n",
                *tmp++, IS_UPPER_CASE(*tmp) ? "true" : "false");

    return 0;
}
