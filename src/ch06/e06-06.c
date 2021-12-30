/* Exercise 06 from chapter 06.
 * Extract an integer and display each digit of the integer in english.
 *
 * Example:
 * 932
 * nine three two
 */

#include <stdio.h>

int main(void)
{
    int number, magnitude;

    printf("Please input a positive integer: ");
    scanf("%i", &number);

    // find the magnitude of the number
    for (magnitude = 1; number / magnitude != 0; magnitude *= 10)
        ;

    // print from most to least significant digit
    for (magnitude /= 10; magnitude > 0; magnitude /= 10) {
        int digit = (number % (magnitude * 10)) / magnitude;

        switch (digit) {
            case 0:
                printf("zero ");
                break;
            case 1:
                printf("one ");
                break;
            case 2:
                printf("two ");
                break;
            case 3:
                printf("three ");
                break;
            case 4:
                printf("four ");
                break;
            case 5:
                printf("five ");
                break;
            case 6:
                printf("six ");
                break;
            case 7:
                printf("seven ");
                break;
            case 8:
                printf("eight ");
                break;
            case 9:
                printf("nine ");
                break;
            default: // this shouldn't be possible...
                printf("??? ");
                break;
        }
    }

    printf("\n");

    return 0;
}

