/* Exercise 03 from chapter 07.
 * Modify Program 7.2 so that any number of responses can be entered. An input
 * of 999 indicates that the last response has been entered.
 */

#include <stdio.h>

int main (void)
{
    const int MAX_RESPONSES = 1024;
    int ratingCounters[11] = {}; // initialize all values to 0
    int i, response;

    printf("Enter your responses\n");

    for (i = 1; i <= MAX_RESPONSES; i++) {
        scanf("%i", &response);

        if (response == 999)
            break;
        else if (response < 1 || response > 10)
            printf("Bad response: %i\n", response);
        else
            ++ratingCounters[response];
    }

    printf("\n\nRating    Number of Responses\n");
    printf("------    -------------------\n");

    for(i = 1; i <= 10; i++)
        printf("%4i%14i\n", i, ratingCounters[i]);

    return 0;
}

