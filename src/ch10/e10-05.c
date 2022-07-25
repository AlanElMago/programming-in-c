/* Exercise 05 from chapter 10.
 * Write a function called find_string to determine if one character string
 * exists inside another string.
 */

#include <stdio.h>

int find_string(const char src[], const char str[])
{
    int i, j;

    for (i = 0; src[i] != '\0'; i++) {
        if (src[i] == str[0]) {
            for (j = 0; src[j + i] == str[j] && str[j] != '\0'; j++)
                ;
            if (str[j] == '\0')
                return i;
        }
    }

    return -1;
}

int main(void)
{
    int index = 0;

    printf("The string \"hat\" is found in \"a chatterbox\" in position %i\n",
            find_string("a chatterbox", "hat"));

    printf("The string \"box\" is found in \"a chatterbox\" in position %i\n",
            find_string("a chatterbox", "box"));

    printf("The string \"bos\" is found in \"a chatterbox\" in position %i\n",
            find_string("a chatterbox", "bos"));

    return 0;
}
