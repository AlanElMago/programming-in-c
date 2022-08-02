/* Exercise 08 from chapter 12.
 * Write a function called bitpat_set to set a specified set of bits to a
 * particular value. The function should take four arguments: a pointer to an
 * unsigned int in which the specified bits are to be set; another unsigned
 * int containing the value to which the specified bits are to be set, right
 * adjusted in the unsigned int; a third int that specifies the starting bit
 * number (with the leftmost bit numbered 0); and a fourth int specifying the
 * size of the field.
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

void bitpat_set(unsigned int *n, const unsigned int pattern,
        const unsigned pos, const unsigned length)
{
    unsigned int offset = int_size() - length - pos;
    unsigned int mask_1 = *n | ( pattern << offset );
    unsigned int mask_2 = ~( ~( ~0 << length ) << offset );
    unsigned int mask_3 = mask_2 | ( pattern << offset );
    
    *n = mask_1 & mask_3;
}

int main(void)
{
    // int n = 0x0962cea5;
    int n = 0x000006d5;
    int bitpat = 0x00000016;
    char bits_string[39];

    int_to_bin_string(n, bits_string);

    printf("n      = %i\n", n);
    printf("n      = %s\n\n", bits_string);

    int_to_bin_string(bitpat, bits_string);

    printf("bitpat = %i\n", bitpat);
    printf("bitpat = %s\n\n", bits_string);

    printf("bitpat_set(n, bitpat, 22, 6)...\n\n");
    bitpat_set(&n, bitpat, 22, 6);

    int_to_bin_string(n, bits_string);

    printf("n      = %i\n", n);
    printf("n      = %s\n\n", bits_string);

    return 0;
}
