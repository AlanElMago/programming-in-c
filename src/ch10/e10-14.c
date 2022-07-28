/* Exercise 14 from chapter 10.
 * Write a function called int_to_str that converts an integer value into a
 * character string.
 */

#include <stdio.h>
#include <stdbool.h>

int absolute_value(int n)
{
    if (n < 0)
        return -n;

    return n;
}

void int_to_str(int n, char out[])
{
    int i;
    int digit;
    int str_length, mid_point;
    char aux;
    bool is_negative = (n < 0);

    if (n == 0) {
        out[0] = '0';
        out[1] = '\0';
        return;
    }

    n = absolute_value(n);

    for (i = 0; n > 0; n /= 10)
        out[i++] = n % 10 + '0';

    if (is_negative)
        out[i++] = '-';

    str_length = i;
    mid_point = str_length / 2;

    for (i = 0; i < mid_point; i++) {
        aux = out[i];
        out[i] = out[str_length - i - 1];
        out[str_length - i - 1] = aux;
    }

    out[str_length] = '\0';
}

int main(void)
{
    int n1 = 12345, n2 = -1234, n3 = 4004, n4 = -404, n5 = 0;
    char str1[10], str2[10], str3[10], str4[10], str5[10];

    printf("n1 = %i\n", n1);
    printf("n2 = %i\n", n2);
    printf("n3 = %i\n", n3);
    printf("n4 = %i\n", n4);
    printf("n5 = %i\n", n5);

    printf("\nConverting numbers to strings...\n\n");

    int_to_str(n1, str1);
    int_to_str(n2, str2);
    int_to_str(n3, str3);
    int_to_str(n4, str4);
    int_to_str(n5, str5);

    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    printf("str3 = %s\n", str3);
    printf("str4 = %s\n", str4);
    printf("str5 = %s\n", str5);

    return 0;
}
