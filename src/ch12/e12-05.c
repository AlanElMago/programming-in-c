/* Exercise 05 from chapter 12.
 * Write a function called bit_test that takes two arguments: an unsigned int
 * and a bit number n. Have the function return 1 bit number n if it is on
 * inside the word, and 0 if it is off.
 */

#include <stdio.h>

int int_size(void)
{
    unsigned int n = ~0;
    int bytes = 0;

    while ( n > 0 ) {
        n >>= 8;
        bytes++;
    }

    return bytes * 8;
}

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

int bit_test(unsigned int n, unsigned const int bit)
{
    int size_of_int = int_size();
    int bit_number;

    if ( bit > size_of_int - 1 )
        return 0;

    return ( 1 << (size_of_int - bit - 1) ) & n;
}

int main(void)
{
    int n = 0x80000845;
    char bits_string[39];

    int_to_bin_string(n, bits_string);

    printf("n = %i\n", n);
    printf("n = %s\n\n", bits_string);

    printf("Is bit 31 on? %s\n", bit_test(n, 31) != 0 ? "True" : "False");
    printf("Is bit 30 on? %s\n", bit_test(n, 30) != 0 ? "True" : "False");
    printf("Is bit 29 on? %s\n", bit_test(n, 29) != 0 ? "True" : "False");
    printf("Is bit 28 on? %s\n", bit_test(n, 28) != 0 ? "True" : "False");
    printf("Is bit 25 on? %s\n", bit_test(n, 25) != 0 ? "True" : "False");
    printf("Is bit 24 on? %s\n", bit_test(n, 24) != 0 ? "True" : "False");
    printf("Is bit 21 on? %s\n", bit_test(n, 21) != 0 ? "True" : "False");
    printf("Is bit 20 on? %s\n", bit_test(n, 20) != 0 ? "True" : "False");
    printf("Is bit  2 on? %s\n", bit_test(n,  2) != 0 ? "True" : "False");
    printf("Is bit  1 on? %s\n", bit_test(n,  1) != 0 ? "True" : "False");
    printf("Is bit  0 on? %s\n", bit_test(n,  0) != 0 ? "True" : "False");

    return 0;
}
