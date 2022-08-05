/* Exercise 07 from chapter 13.
 * Write a macro IS_ALPHABETIC that gives a nonzero value if a character is
 * an alphabetic character. Have the macro use the IS_LOWER_CASE macro defined
 * in the chapter text and the IS_UPPER_CASE macro defined in exercise 6.
 */

#define IS_UPPER_CASE(c) ( (c) >= 'A' && (c) <= 'Z' ? (c) : 0 )
#define IS_LOWER_CASE(c) ( (c) >= 'a' && (c) <= 'z' ? (c) : 0 )
#define IS_ALPHABETIC(c) ( IS_UPPER_CASE(c) || IS_LOWER_CASE(c) ? (c) : 0 )

#include <stdio.h>

int main(void)
{
    char *str = "L337 H4x0r L4ngu4g3!";
    char *tmp = str;

    printf("%s\n\n", str);

    while ( *tmp != '\0' )
        printf("Is %c an alphaberic character? %s\n",
                *tmp++, IS_ALPHABETIC(*tmp) ? "true" : "false");

    return 0;
}
