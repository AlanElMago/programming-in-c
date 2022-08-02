/* Exercise 07 from chapter 12.
 * Write a function called bitpat_get to extract a specified set of bits. Have
 * it three arguments: the first an unsigned int, the second an integer
 * starting bit number, and the third a bit count.
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

int bitpat_get(const unsigned int n, const unsigned int pos,
        const unsigned int length)
{
    int mask = ~( ~0 << length );
    int offset = int_size() - length - pos;

    return ( n >> offset ) & mask;
}

int main(void)
{
    int n = 0x0962cea5;
    int bitpat = 0;
    char bits_string[39];

    int_to_bin_string(n, bits_string);

    printf("n = %i\n", n);
    printf("n = %s\n\n", bits_string);

    bitpat = bitpat_get(n, 7, 5);
    int_to_bin_string(bitpat, bits_string);
    printf("bitpat_get(m,  7,  5) = %s\n", bits_string);

    bitpat = bitpat_get(n, 24, 6);
    int_to_bin_string(bitpat, bits_string);
    printf("bitpat_get(m, 24,  6) = %s\n", bits_string);

    bitpat = bitpat_get(n, 16, 12);
    int_to_bin_string(bitpat, bits_string);
    printf("bitpat_get(m, 16, 12) = %s\n", bits_string);

    return 0;
}
