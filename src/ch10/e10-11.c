/* Exercise 11 from chapter 10.
 * Extend the str_to_int function from Program 10.11 so that if the first
 * character of the string is a minus sign, the value that follows is taken
 * as a negative number.
 */

#include <stdio.h>
#include <stdbool.h>

int str_to_int(const char string[])
{
    int i = 0, int_value, result = 0;
    bool is_negative = false;

    if (string[i] == '-') {
        is_negative = true;
        i++;
    }

    for (; string[i] >= '0' && string[i] <= '9'; ++i)
    {
        int_value = string[i] - '0';
        result = result * 10 + int_value;
    }

    if (is_negative)
        return -result;

    return result;
}

int main(void)
{
    int str_to_int(const char string[]);

    printf("%i\n", str_to_int("245"));
    printf("%i\n", str_to_int("100") + 25);
    printf("%i\n", str_to_int("13x5"));
    printf("%i\n", str_to_int("-123"));
    printf("%i\n", str_to_int("-160") + 150);

    return 0;
}
