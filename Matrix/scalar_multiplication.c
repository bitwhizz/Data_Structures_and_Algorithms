/*

Program for scalar multiplication of a matrix

Given a matrix and a scalar element k,
our task is to find out the scalar product of that matrix.

*/


// C program to find the scalar product
// of a matrix
#include <stdio.h>

// Size of given matrix
#define N 3

void scalarProductMat(int mat[][N], int k)
{
    // scalar element is multiplied by the matrix
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            mat[i][j] = mat[i][j] * k;
}

// Driver code
int main()
{
    int mat[N][N] = { { 1, 2, 3 },
                      { 4, 5, 6 },
                      { 7, 8, 9 } };
    int k = 4;

    scalarProductMat(mat, k);

    // to display the resultant matrix
    printf("Scalar Product Matrix is : \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }

    return 0;
}
