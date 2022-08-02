/* Exercise 06 from chapter 12.
 * Write a function called bitpat_search that looks for the occurence of a
 * specified pattern of bits inside an unsigned int.
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

int bitpat_search(const unsigned int n, const unsigned int pattern,
        const unsigned int pattern_size)
{
    int size_of_int = int_size();
    int mask = ~( ~0 << pattern_size );
    int i;

    for ( i = 0; i <= size_of_int - pattern_size; i++ )
        if ( ( ( mask << i ) & n ) == pattern << i )
            return size_of_int - pattern_size - i;

    return -1;
}

int main(void)
{
    int n = 0x80000845;
    char bits_string[39];

    int_to_bin_string(n, bits_string);

    printf("n = %i\n", n);
    printf("n = %s\n\n", bits_string);

    printf("Pattern %s found in bit %i.\n",
            "101", bitpat_search(n, 0x5, 3));
    printf("Pattern %s found in bit %i.\n",
            "100001", bitpat_search(n, 0x21, 6));

    return 0;
}
