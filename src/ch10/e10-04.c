/* Exercise 04 form chapter 10.
 * Write a function called substring to extract a portion of a character
 * string.
 */

#include <stdio.h>

void substring(const char source[], int start, int count, char result[])
{
    int i;
    int end = start + count;

    for (i = 0; (i + start) < end && source[i + start] != '\0'; i++)
        result[i] = source[i + start];

    result[i] = '\0';
}

int main(void)
{
    char substr1[20], substr2[20];

    substring("character", 4, 3, substr1);
    substring("two words", 4, 20, substr2);
    
    printf("Substring from \"character\" where start = 4 and count = 3: %s\n",
            substr1);
    printf("Substring from \"two words\" where start = 4 and count = 20: %s\n",
            substr2);

    return 0;
}
