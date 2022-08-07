/* Exercise 04 from chapter 16.
 * Write a program that merges lines alternately from two files and writes
 * the results to stdouy. If one file has less lines than the other, the
 * remaining lines from the larger file should simply be copied to stdout.
 */

#include <stdio.h>

int main()
{
    char in_file_name_1[128], in_file_name_2[128];
    FILE *in_file_1, *in_file_2;
    int c1 = 0, c2 = 0;

    printf("Input file 1: ");
    scanf("%127s", in_file_name_1);
    printf("Input file 2: ");
    scanf("%127s", in_file_name_2);

    if ( (in_file_1 = fopen(in_file_name_1, "r")) == NULL ) {
        fprintf(stderr, "Can't open %s for reading.\n", in_file_name_1);
        return 1;
    }

    if ( (in_file_2 = fopen(in_file_name_2, "r")) == NULL ) {
        fprintf(stderr, "Can't open %s for reading.\n", in_file_name_2);
        return 1;
    }

    putc('\n', stdout);

    while ( c1 != EOF || c2 != EOF ) {

        while ( c1 != '\n' && c1 != EOF ) {
            putc(c1, stdout);
            c1 = getc(in_file_1);
        }

        if ( c1 != EOF )
            putc('\n', stdout);

        while ( c2 != '\n' && c2 != EOF ) {
            putc(c2, stdout);
            c2 = getc(in_file_2);
        }

        if (c2 != EOF )
            putc('\n', stdout);

        c1 = getc(in_file_1);
        c2 = getc(in_file_2);
    }

    fclose(in_file_1);
    fclose(in_file_2);

    return 0;
}
