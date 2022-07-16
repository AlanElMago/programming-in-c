/* Exercise 12b from chapter 08.
 * Rewrite the transposeMatrix in exercise 12a to take the number of rows and
 * columns as arguments, and to transpose the matrix of the specified
 * dimensions.
 */

#include <stdio.h>

void transpose_matrix(int rows, int columns,
        int in_matrix[rows][columns], int out_matrix[columns][rows])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
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
    int m1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int m2[4][5] = {
        { 1,  2,  3,  4,  5},
        { 6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };

    int m3[10][2] = {
        { 1,  2},
        { 3,  4},
        { 5,  6},
        { 7,  8},
        { 9, 10},
        {11, 12},
        {13, 14},
        {15, 16},
        {17, 18},
        {19, 20},
    };

    int n1[3][3] = {0};
    int n2[5][4] = {0};
    int n3[2][10] = {0};

    transpose_matrix(3, 3, m1, n1);
    transpose_matrix(4, 5, m2, n2);
    transpose_matrix(10, 2, m3, n3);

    printf("Matrix M1:\n");
    print_matrix(3, 3, m1);
    printf("\nMatrix N1:\n");
    print_matrix(3, 3, n1);

    printf("\nMatrix M2:\n");
    print_matrix(4, 5, m2);
    printf("\nMatrix N2:\n");
    print_matrix(5, 4, n2);

    printf("\nMatrix M3:\n");
    print_matrix(10, 2, m3);
    printf("\nMatrix N3:\n");
    print_matrix(2, 10, n3);

    return 0;
}
