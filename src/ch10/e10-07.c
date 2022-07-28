/* Exercise 07 from chapter 10.
 * Write a function called insert_string to insert one character string into
 * another string. The arguments to the function should consist of the source
 * string, the string to be inerted, and the position in the source string
 * where the string is to be inserted.
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
    int i, j;
    int str_length = string_length(str);

    // set i to null character position in src
    for (i = 0; src[i] != '\0'; i++)
        ;

    // copy the last n characters of src to position i + str_length, where
    // n = str_length
    for (j = 0; j <= str_length + 1; j++)
        src[i-- + str_length] = src[i];

    // copy str to src at pos
    for (i = 0; i < str_length; i++)
        src[i + pos] = str[i];
}

int main(void)
{
   char str1[20] = "The wrong son.";
   char str2[20] = "Hello, world!";

   printf("str1: %s\n", str1);
   insert_string(str1, "per", 10);
   printf("insert_string(str1, \"per\", 10): %s\n\n", str1);

   printf("str2: %s\n", str2);
   insert_string(str2, "cruel ", 7);
   printf("insert_string(str2, \"cruel \", 7): %s\n\n", str2);

   return 0;
}
