/* Exercise 13 from chapter 10.
 * Write a function called uppercase that converts all lowercase characters in
 * a string into their uppercase equivalents.
 */

#include <stdio.h>

void uppercase(char src[])
{
    for (int i = 0; src[i] != '\0'; i++)
        src[i] = (src[i] < 'a' || src[i] > 'z') * src[i] +
                (src[i] >= 'a' && src[i] <= 'z') * (src[i] - 32);
}

int main(void)
{
    char str1[] = "I am not speaking loudly.";
    char str2[] = "\"Did you put your name into the Goblet of Fire?\" "
            "he asked calmly.";

    printf("str1: %s\n", str1);
    uppercase(str1);
    printf("str1 uppercase: %s\n\n", str1);

    printf("str2: %s\n", str2);
    uppercase(str2);
    printf("str2 uppercase: %s\n\n", str2);

    return 0;
}
