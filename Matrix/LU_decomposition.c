/*
Let A be a square matrix. An LU factorization refers to the factorization of A,
 with proper row and/or column orderings or permutations,
into two factors, a lower triangular matrix L and an upper triangular matrix U,
 A=LU.

 Doolittle Algorithm :
It is always possible to factor a square matrix into a lower triangular matrix and an upper triangular matrix.
That is, [A] = [L][U]

Doolittle’s method provides an alternative way to factor A into an LU decomposition
 without going through the hassle of Gaussian Elimination.

Refer the link for more understanding
 https://www.geeksforgeeks.org/doolittle-algorithm-lu-decomposition/#:~:text=The%20LU%20decomposition%20was%20introduced,matrix%20U%2C%20A%3DLU.
*/

// CPP Program to decompose a matrix into
// lower and upper traingular matrix
#include <stdio.h>
#include <string.h>

#define MAX 100

void luDecomposition(int mat[][MAX], int n)
{
    int lower[n][n], upper[n][n];
    memset(lower, 0, sizeof(lower));
    memset(upper, 0, sizeof(upper));

    // Decomposing matrix into Upper and Lower
    // triangular matrix
    for (int i = 0; i < n; i++) {

        // Upper Triangular
        for (int k = i; k < n; k++) {

            // Summation of L(i, j) * U(j, k)
            int sum = 0;
            for (int j = 0; j < i; j++)
                sum += (lower[i][j] * upper[j][k]);

            // Evaluating U(i, k)
            upper[i][k] = mat[i][k] - sum;
        }

        // Lower Triangular
        for (int k = i; k < n; k++) {
            if (i == k)
                lower[i][i] = 1; // Diagonal as 1
            else {

                // Summation of L(k, j) * U(j, i)
                int sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (lower[k][j] * upper[j][i]);

                // Evaluating L(k, i)
                lower[k][i] = (mat[k][i] - sum) / upper[i][i];
            }
        }
    }

    // setw is for displaying nicely
    printf("Lower Triangular \n");

    // Displaying the result :
    for (int i = 0; i < n; i++) {
        // Lower
        for (int j = 0; j < n; j++)
            printf("%d  ",lower[i][j]);

        printf("\n");
    }

    printf("Upper Triangular\n");
    for (int i = 0; i < n; i++) {
        // Upper
        for (int j = 0; j < n; j++)
            printf("%d  ",upper[i][j]);
      printf("\n");
    }
}

// Driver code
int main()
{
    int mat[][MAX] = { { 2, -1, -2 },
                       { -4, 6, 3 },
                       { -4, -2, 8 } };

    luDecomposition(mat, 3);
    return 0;
}
