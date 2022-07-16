/* Exercise 12a from chapter 08.
 * Write a function transposeMatrix that takes as an argument a 4 x 5 matrix
 * and a 5 x 4 matrix. Have the function transpose the 4x5 matrix and store
 * the results in the 5 x 4 matrix.
 */

#include <stdio.h>

void transpose_matrix(int in_matrix[4][5], int out_matrix[5][4])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            out_matrix[j][i] = in_matrix[i][j];
}

void print_matrix(int rows, int columns, int m[rows][columns])
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            printf("%3d ", m[i][j]);

        printf("\n");
    }
}

int main(void)
{
    int m[4][5] = {
        { 1,  2,  3,  4,  5},
        { 6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };

    int n[5][4] = {0};

    transpose_matrix(m, n);

    printf("Matrix M:\n");
    print_matrix(4, 5, m);
    printf("\nMatrix N:\n");
    print_matrix(5, 4, n);

    return 0;
}
