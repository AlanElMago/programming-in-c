/* Exercise 04 from chapter 06.
 * Simple "printing" calculator. Allows the user to type in expressions of the
 * form:
 *      number  operator
 *
 * The following operations are recognized:
 *      +   Addition
 *      -   Subraction
 *      *   Multiplication
 *      /   Division
 *      S   Set accumulator
 *      E   Exit program
 */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    float number;
    float accumulator = 0;
    char operator;
    bool terminate = false;

    printf("Begin Calculations\n");

    while (!terminate) {
        scanf("%f %c", &number, &operator);

        switch (operator) {
            case '+':
                accumulator += number;
                break;
            case '-':
                accumulator -= number;
                break;
            case '*':
                accumulator *= number;
                break;
            case '/':
                if (number == 0)
                    printf("Division by zero.\n");
                else
                    accumulator /= number;
                break;
            case 'S':
                accumulator = number;
                break;
            case 'E':
                terminate = true;
                break;
            default:
                printf("Unknown operator.\n");
                break;
        }

        printf("= %f\n", accumulator);
    }

    printf("End of Calculations.\n");

    return 0;
}

