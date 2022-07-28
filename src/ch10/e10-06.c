/* Exercise 06 from chapter 10.
 * Write a function called remove_string to remove a specified number of
 * characters from a character string. The function should take three
 * arguments: the source string, the starting index number in the source
 * string, and the number of characters to remove.
 */

#include <stdio.h>

void remove_string(char src[], int index, int count)
{
    int i;

    for (i = index; src[i + count] != '\0'; i++)
        src[i] = src[i + count];

    src[i] = '\0';
}

int main(void)
{
    char str1[] = "The wrong son.";
    char str2[] = "Hello, cruel world!";
    char str3[] = "Lighghght is spelt L-I-G-H-T.";

    printf("str1: %s\n", str1);
    remove_string(str1, 4, 6);
    printf("remove_string(str1, 4, 6): %s\n\n", str1);

    printf("str2: %s\n", str2);
    remove_string(str2, 6, 6);
    printf("remove_string(str2, 6, 6): %s\n\n", str2);

    printf("str3: %s\n", str3);
    remove_string(str3, 2, 4);
    printf("remove_string(str3, 2, 4): %s\n\n", str3);

    return 0;
}
