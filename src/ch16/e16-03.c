/* Exercise 03 from chapter 16.
 * Write a program to copy one file into another, replacing all lowercase
 * characters with their uppercase equivialents.
 */

#define IS_LOWER(c) ( (c) >= 'a' && (c) <= 'z' ? (c) : 0 )
#define TO_UPPER(c) ( IS_LOWER(c) ? (c) ^ 0x20 : (c) )

#include <stdio.h>

int main()
{
    char in_file_name[128], out_file_name[128];
    FILE *in_file, *out_file;
    int c;

    printf("Input file: ");
    scanf("%127s", in_file_name);
    printf("Output file: ");
    scanf("%127s", out_file_name);

    if ( (in_file = fopen(in_file_name, "r")) == NULL ) {
        fprintf(stderr, "Can't open %s for reading.\n", in_file_name);
        return 1;
    }

    if ( (out_file = fopen(out_file_name, "w")) == NULL ) {
        fprintf(stderr, "Can't open %s for writing.\n", out_file_name);
        return 2;
    }

    while ( (c = getc(in_file)) != EOF )
        putc( TO_UPPER(c), out_file );

    fclose(in_file);
    fclose(out_file);

    printf("File has been copied.\n");

    return 0;
}
