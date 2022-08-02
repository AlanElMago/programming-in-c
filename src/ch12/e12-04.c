/* Exercise 04 from chapter 12.
 * Using the result obtained in exercise 3, modigy the rotate function from
 * Program 12.4 so that it no longer makes assumtions about the size of an
 * int.
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

// Function to rotate an unsigned int left to right

unsigned int rotate(unsigned int value, int n)
{
    short size_of_int = int_size();
    unsigned int result, bits;

    // scale down the shift count to a defined range

    if ( n > 0 )
        n = n % size_of_int;
    else
        n = -(-n % size_of_int);

    if ( n == 0 )
        result = value;
    else if ( n > 0 ) {     // left rotate
        bits = value >> (size_of_int - n);
        result = value << n | bits;
    }
    else {                  // right rotate
        n = -n;
        bits = value << (size_of_int - n);
        result = value >> n | bits;
    }

    return result;
}

int main(void)
{
    unsigned int w1 = 0xabcdef00u, w2 = 0xffff1122u;
    unsigned int rotate(unsigned int value, int n);

    printf("%x\n", rotate(w1, 8));
    printf("%x\n", rotate(w1, -16));
    printf("%x\n", rotate(w2, 4));
    printf("%x\n", rotate(w2, -2));
    printf("%x\n", rotate(w1, 0));
    printf("%x\n", rotate(w1, 44));

    return 0;
}
