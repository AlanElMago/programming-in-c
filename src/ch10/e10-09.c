/* Exercise 09 from chapter 10.
 * Write a funtion called replace_strings that replaces all strings in a
 * character string.
 */

#include <stdio.h>
#include <stdbool.h>

int string_length(const char str[])
{
    int length;

    for (length = 0; str[length] != '\0'; length++)
        ;

    return length;
}

void insert_string(char src[], const char str[], int pos)
{
    int i;
    int str_length = string_length(str);

    for (i = 0; src[i] != '\0'; i++)
        ;

    for (i; i >= pos; i--)
        src[i + str_length] = src[i];

    for (i = 0; i < str_length; i++)
        src[i + pos] = str[i];
}

void remove_string(char src[], int index, int count)
{
    int i;

    for (i = index; src[i + count] != '\0'; i++)
        src[i] = src[i + count];

    src[i] = '\0';
}

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

bool replace_string(char src[], const char s1[], const char s2[])
{
    int pos = find_string(src, s1);

    if (pos == -1)
        return false;

    int s1_length = string_length(s1);

    remove_string(src, pos, s1_length);
    insert_string(src, s2, pos);

    return true;
}

void replace_strings(char src[], const char s1[], const char s2[])
{
    while (replace_string(src, s1, s2))
        ;
}

int main(void)
{
    char str1[50] = "It's one of a kind; one in one hundred.";
    char str2[50] = "This is a very short string.";
    char str3[90] = "The microscopic man who lived in a microscopic house "
            "sat on a microscopic chair.";

    printf("str1: %s\n", str1);
    replace_strings(str1, "one", "two");
    printf("replace_strings(str1, \"one\", \"two\"): %s\n\n", str1);

    printf("str2: %s\n", str2);
    replace_strings(str2, " ", "");
    printf("replace_strings(str2, \" \", \"\"): %s\n\n", str2);

    printf("str3: %s\n", str3);
    replace_strings(str3, "microscopic", "tall");
    printf("replace_strings(str3, \"microscopic\", \"tall\"): %s\n\n", str3);

    return 0;
}
