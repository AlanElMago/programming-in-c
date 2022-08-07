// Program to copy one file to another

#include <stdio.h>

int main(void)
{
    char in_name[64], out_name[64];
    FILE *in, *out;
    int  c;

    // get file names from user

    printf("Enter name of file to be copied: ");
    scanf("%63s", in_name);
    printf("Enter name of output file: ");
    scanf("%63s", out_name);

    // open input and output files
    
    if ( (in = fopen(in_name, "r")) == NULL ) {
        printf("Can't open %s for reading.\n", in_name);
        return 1;
    }

    if ( (out = fopen(out_name, "w")) == NULL ) {
        printf("Can't open %s for writing.\n", out_name);
        return 2;
    }

    // copy in to out
    
    while ( (c = getc(in)) != EOF )
        putc(c, out);
    
    // close open files

    fclose(in);
    fclose(out);

    printf("File has been copied.\n");

    return 0;
}
