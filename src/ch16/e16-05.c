/* Exercise 05 from chapter 16.
 * Write a program that writes columns m through n of each line of a file to
 * stdout. Have the program accept the values of m and n from the terminal
 * window.
 */

#include <stdio.h>

int main()
{
    char in_file_name[128];
    FILE *in_file;
    int c = 0;
    int m, n;

    printf("Input file: ");
    scanf("%127s", in_file_name);
    printf("Columns [m-n]: ");
    scanf("%i-%i", &m, &n);

    if ( (in_file = fopen(in_file_name, "r")) == NULL ) {
        fprintf(stderr, "Can't open %s for reading.\n", in_file_name);
        return 1;
    }

    putc('\n', stdout);

    while ( c != EOF ) {
        c = getc(in_file);

        for ( int i = 0; c != '\n' && c != EOF; c = getc(in_file), i++ ) {

            if ( i < m ) continue;

            if ( i <= n ) putc(c, stdout);
        }

        putc('\n', stdout);
    }

    fclose(in_file);

    return 0;
}
