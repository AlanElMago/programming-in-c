/* Exercise 08 from chapter 13.
 * Write a macro IS_DIGIT that gives a nonzero value if a character is a digit
 * '0' through '9'. Use this macro in the definition of another macro
 * IS_SPECIAL, which gives a nonzero result of a character is a special
 * character; that is, not aphabetic and not a digit. Be certain to use the
 * is IS_ALPHABETIC macro developed in exercise 7.
 */

#define IS_UPPER_CASE(c) ( (c) >= 'A' && (c) <= 'Z' ? (c) : 0 )
#define IS_LOWER_CASE(c) ( (c) >= 'a' && (c) <= 'z' ? (c) : 0 )
#define IS_ALPHABETIC(c) ( IS_UPPER_CASE(c) || IS_LOWER_CASE(c) ? (c) : 0 )
#define IS_DIGIT(c) ( (c) >= '0' && (c) <= '9' ? (c) : 0 )
#define IS_SPECIAL(c) ( !IS_ALPHABETIC(c) && !IS_DIGIT(c) ? (c) : 0 )

#include <stdio.h>

int main(void)
{
    char *str = "7#!S I$ @ V3rY (Ryp71( 73%t!";
    char *tmp = str;

    printf("%s\n\n", str);

    while ( *tmp != '\0' )
        printf("Is %c a special character? %s\n",
                *tmp++, IS_SPECIAL(*tmp) ? "true" : "false");

    return 0;
}
