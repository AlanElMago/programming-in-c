/* Exercise 06 from chapter 07.
 * Rewrite Program 7.3 so that arrays are not used.
 */

#include <stdio.h>

int main(void)
{
    long long unsigned int f;   // current Fibonacci number
    long long unsigned int f_1; // first predecessor of f
    long long unsigned int f_2; // second predecessor of f
    int sequence_len;

    printf("How many fibonacci numbers to generate (between 1 and 75)? ");
    scanf("%i", &sequence_len);

    if (sequence_len < 1 || sequence_len > 75) {
        printf("Out of range. Aborting...\n");
        return 1;
    }

    // print the first number of the fibonacci sequence
    printf("0 ");

    // if the requested sequence length is 1, abort
    if (sequence_len == 1) {
        printf("\n");
        return 0;
    }

    // print the second number of the fibonacci sequence
    printf("1 ");

    // if the requested sequence length is 2, abort
    if (sequence_len == 2) {
        printf("\n");
        return 0;
    }

    f_2 = 0;    // first number of the fibonacci sequence
    f_1 = 1;    // second number of the fibonacci sequence

    // generate and print the fibonacci sequence starting from the third
    // number up to the requested sequence length
    for (int i = 2; i < sequence_len; i++) {
        f = f_1 + f_2;      // calculate the next fibonacci number

        printf("%lli ", f);   // print it

        f_2 = f_1;          // the value of f_1 is transposed to f_2
        f_1 = f;            // the value of f is transposed to f_1
    }

    printf("\n");

    return 0;
}

