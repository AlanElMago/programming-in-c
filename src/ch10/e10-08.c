/* Exercise 08 from chapter 10.
 * Write a funtion called replace_string that takes three character string
 * arguments.
 */

#include <stdio.h>

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

void replace_string(char src[], const char s1[], const char s2[])
{
    int pos = find_string(src, s1);
    int s1_length = string_length(s1);

    remove_string(src, pos, s1_length);
    insert_string(src, s2, pos);
}

int main(void)
{
    char str1[30] = "Hello, cruel world!";
    char str2[30] = "It's over 9000!";
    char str3[30] = "It's one of a kind.";

    printf("str1: %s\n", str1);
    replace_string(str1, "cruel", "beautiful");
    printf("replace_string(str1, \"cruel\", \"beautiful\"): %s\n\n", str1);

    printf("str2: %s\n", str2);
    replace_string(str2, "9000", "nine thousand");
    printf("replace_string(str2, \"9000\", \"nine thousand\"): %s\n\n", str2);

    printf("str3: %s\n", str3);
    replace_string(str3, "one", "two");
    printf("replace_string(str3, \"one\", \"two\"): %s\n\n", str3);

    return 0;
}
