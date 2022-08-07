/* Exercise 06 from chapter 16.
 * Write a program that displays the contents of a file at the terminal 20
 * lines at a time. At the end of each 20 lines, have the program wait for a
 * character to be entered from the terminal. If the character is the letter
 * q, the program should stop the display of the file; any other character
 * should cause the next 20 lines from the file to be displayed.
 */

#define LINES_PER_PROMPT 20

#include <stdio.h>
#include <stdbool.h>

int main()
{
    char in_file_name[128];
    FILE *in_file;
    bool prompted = true;
    int lines = 0;
    int c, in_c;

    printf("Input file: ");
    scanf("%127s", in_file_name);
    putc('\n', stdout);

    for ( in_c = getc(stdin); in_c != '\n' && in_c != EOF; in_c = getc(stdin) )
        ;

    if ( (in_file = fopen(in_file_name, "r")) == NULL ) {
        fprintf(stderr, "Can't open %s for reading.\n", in_file_name);
        return 1;
    }

    while ( (c = getc(in_file)) != EOF ) {

        if ( c == '\n') {
            lines++;
            prompted = false;
        }

        putc(c, stdout);

        if ( lines % LINES_PER_PROMPT == 0 && !prompted ) {
            printf("--- %i lines displayed. Press enter to continue or enter "
                    "q to quit. ---\r", lines);
            in_c = getc(stdin);

            if ( in_c == 'q' ) break;

            prompted = true;

            printf("\033[1A%80s\r", " ");
        }
    }

    if ( c == EOF )
        printf("--- %i lines displayed. End of File ---\n", lines);

    fclose(in_file);

    return 0;
}
