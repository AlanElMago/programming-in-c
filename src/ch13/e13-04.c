/* Exercise 04 from chapter 13.
 * Define a macro MAX3 that gives the maximum of three values. Write a program
 * to test the definition.
 */

#define MAX3(a, b, c) ( (a) > (b) ? \
        ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c)) )

#include <stdio.h>

int main(void) {
    printf("MAX3(333,  22,   1) = %i\n", MAX3(333, 22, 1));
    printf("MAX3(333,   1,  22) = %i\n", MAX3(333, 1, 22));
    printf("MAX3( 22, 333,   1) = %i\n", MAX3(22, 333, 1));
    printf("MAX3( 22,   1, 333) = %i\n", MAX3(22, 1, 333));
    printf("MAX3(  1, 333,  22) = %i\n", MAX3(1, 333, 22)); 
    printf("MAX3(  1,  22, 333) = %i\n", MAX3(1, 22, 333));

    return 0;
}
