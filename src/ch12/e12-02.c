/* Exercise 02 from chapter 12.
 * Write a program that determines whether your particular computer performs
 * an arithmetic or a logical right shift.
 */

#include <stdio.h>
#include <stdbool.h>

int int_to_bin_string(int n, char *out)
{
    static const short STRING_LENGTH = 39;
    char aux[STRING_LENGTH];
    int i = 0;

    while ( i < STRING_LENGTH ) {

        if ( (i + 1) % 5 == 0 )
            aux[i++] = ' ';

        aux[i++] = (n & 1) + '0';
        n >>= 1;
    }

    while ( i > 0 )
        *out++ = aux[--i];

    *out = '\0';
}

bool is_arithmetic_right_shift(void)
{
    return ( (int) 0x80000000 ) >> 1 == (int) 0xc0000000;
}

int main(void)
{
    int n = 0x80000000;
    int m = 0xa0000000;
    char bits_string[39];

    if ( is_arithmetic_right_shift() )
        printf("Your computer uses \"Arithmetic Right Shift\".\n");
    else
        printf("Your computer uses \"Logical Right Shift\".\n");

    printf("\nExample:\n");

    int_to_bin_string(n, bits_string);

    printf("n      = %i\n", n);
    printf("n      = %s\n", bits_string);

    int_to_bin_string(n >> 1, bits_string);

    printf("n >> 1 = %i\n", n >> 1);
    printf("n >> 1 = %s\n", bits_string);

    return 0;
}
