/*
Sparse Matrix Representations

If most of the elements in the matrix are zero then the matrix is called a sparse matrix.
It is wasteful to store the zero elements in the matrix since they do not affect the results of our computation.
This is why we implement these matrices in more efficient representations than the standard 2D Array.
Using more efficient representations we can cut down space and time complexities of operations significantly.

The CSR (Compressed Sparse Row) or the Yale Format is similar to the Array Representation of Sparse Matrix.

We represent a matric M (m * n), by three 1-D arrays or vectors called as A, IA, JA. Let NNZ denote the number of non-zero elements in M and note that 0-based indexing is used.

The A vector is of size NNZ and it stores the values of the non-zero elements of the matrix. The values appear in the order of traversing the matrix row-by-row
The IA vector is of size m+1 stores the cumulative number of non-zero elements upto ( not including) the i-th row. It is defined by the recursive relation :
IA[0] = 0
IA[i] = IA[i-1] + no of non-zero elements in the (i-1) th row of the Matrix
The JA vector stores the column index of each element in the A vector. Thus it is of size NNZ as well.

Algorithm

SPARSIFY (MATRIX)
Step 1: Set M to number of rows in MATRIX
Step 2: Set N to number of columns in MATRIX
Step 3: I = 0, NNZ = 0. Declare A, JA, and IA.
        Set IA[0] to 0
Step 4: for I = 0 ... N-1
Step 5: for J = 0 ... N-1
Step 5: If MATRIX [I][J] is not zero
           Add MATRIX[I][J] to A
           Add J to JA
           NNZ = NNZ + 1
        [End of IF]
Step 6: [ End of J loop ]
        Add NNZ to IA
        [ End of I loop ]
Step 7: Print vectors A, IA, JA
Step 8: END

*/

// CPP program to find sparse matrix rep-
// resentation using CSR
#include <stdio.h>
#include <stdlib.h>
#define VECTOR_INIT_CAPACITY 6
#define UNDEFINE  -1
#define SUCCESS 0
#define VECTOR_INIT(vec) vector vec;\
 vector_init(&vec)

#define M 4
#define N 5

//Store and track the stored data
typedef struct sVectorList
{
    void **items;
    int capacity;
    int total;
} sVectorList;

//structure contain the function pointer
typedef struct sVector vector;
struct sVector
{
    sVectorList vectorList;
//function pointers
    int (*pfVectorTotal)(vector *);
    int (*pfVectorResize)(vector *, int);
    int (*pfVectorAdd)(vector *, void *);
    int (*pfVectorSet)(vector *, int, void *);
    void *(*pfVectorGet)(vector *, int);
    int (*pfVectorDelete)(vector *, int);
    int (*pfVectorFree)(vector *);
};

int vectorTotal(vector *v)
{
    int totalCount = UNDEFINE;
    if(v)
    {
        totalCount = v->vectorList.total;
    }
    return totalCount;
}

int vectorResize(vector *v, int capacity)
{
    int  status = UNDEFINE;
    if(v)
    {
        void **items = realloc(v->vectorList.items, sizeof(void *) * capacity);
        if (items)
        {
            v->vectorList.items = items;
            v->vectorList.capacity = capacity;
            status = SUCCESS;
        }
    }
    return status;
}

int vectorPushBack(vector *v, void *item)
{
    int  status = UNDEFINE;
    if(v)
    {
        if (v->vectorList.capacity == v->vectorList.total)
        {
            status = vectorResize(v, v->vectorList.capacity * 2);
            if(status != UNDEFINE)
            {
                v->vectorList.items[v->vectorList.total++] = item;
            }
        }
        else
        {
            v->vectorList.items[v->vectorList.total++] = item;
            status = SUCCESS;
        }
    }
    return status;
}

int vectorSet(vector *v, int index, void *item)
{
    int  status = UNDEFINE;
    if(v)
    {
        if ((index >= 0) && (index < v->vectorList.total))
        {
            v->vectorList.items[index] = item;
            status = SUCCESS;
        }
    }
    return status;
}

void *vectorGet(vector *v, int index)
{
    void *readData = NULL;
    if(v)
    {
        if ((index >= 0) && (index < v->vectorList.total))
        {
            readData = v->vectorList.items[index];
        }
    }
    return readData;
}

int vectorDelete(vector *v, int index)
{
    int  status = UNDEFINE;
    int i = 0;
    if(v)
    {
        if ((index < 0) || (index >= v->vectorList.total))
            return status;
        v->vectorList.items[index] = NULL;
        for (i = index; (i < v->vectorList.total - 1); ++i)
        {
            v->vectorList.items[i] = v->vectorList.items[i + 1];
            v->vectorList.items[i + 1] = NULL;
        }
        v->vectorList.total--;
        if ((v->vectorList.total > 0) && ((v->vectorList.total) == (v->vectorList.capacity / 4)))
        {
            vectorResize(v, v->vectorList.capacity / 2);
        }
        status = SUCCESS;
    }
    return status;
}

int vectorFree(vector *v)
{
    int  status = UNDEFINE;
    if(v)
    {
        free(v->vectorList.items);
        v->vectorList.items = NULL;
        status = SUCCESS;
    }
    return status;
}

void vector_init(vector *v)
{
    //init function pointers
    v->pfVectorTotal = vectorTotal;
    v->pfVectorResize = vectorResize;
    v->pfVectorAdd = vectorPushBack;
    v->pfVectorSet = vectorSet;
    v->pfVectorGet = vectorGet;
    v->pfVectorFree = vectorFree;
    v->pfVectorDelete = vectorDelete;
    //initialize the capacity and allocate the memory
    v->vectorList.capacity = VECTOR_INIT_CAPACITY;
    v->vectorList.total = 0;
    v->vectorList.items = malloc(sizeof(void *) * v->vectorList.capacity);
}

// Utility Function to print a Matrix
void printMatrix(int matrix[][N])
{
    int m = M;
    int n = N;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Generate the three vectors A, IA, JA
void sparesify(int matrix[][N])
{
    int m = M;
    int n = N, i, j;

    //init vector
    VECTOR_INIT(A);
    VECTOR_INIT(IA);
    VECTOR_INIT(JA);

    //vi A;
    //vi IA = { 0 }; // IA matrix has N+1 rows
    //vi JA;

    IA.pfVectorSet(&IA,0,0);   ////vi IA = { 0 }; // IA matrix has N+1 rows

    int NNZ = 0;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                A.pfVectorAdd(&A,matrix[i][j]);
                JA.pfVectorAdd(&JA,j);

                // Count Number of Non Zero
                // Elements in row i
                NNZ++;
            }
        }
        IA.pfVectorAdd(&IA,NNZ);
    }

    printMatrix(matrix);

    printf("A = [");
    //print the data and type cast it
    for (i = 0; i < A.pfVectorTotal(&A); i++)
    {
        printf("%d  ",(int *)A.pfVectorGet(&A, i));
    }
    printf("]\n");

    printf("IA= [");
    //print the data and type cast it
    for (i = 0; i < IA.pfVectorTotal(&IA); i++)
    {
        printf("%d  ",(int *)IA.pfVectorGet(&IA, i));
    }
    printf("]\n");

    printf("JA = [");
    //print the data and type cast it
    for (i = 0; i < JA.pfVectorTotal(&JA); i++)
    {
        printf("%d  ",(int *)JA.pfVectorGet(&JA, i));
    }
    printf("]\n");

}

// Driver code
int main()
{
    int Matrix[M][N] = {
        { 0, 0, 0, 0, 1 },
        { 5, 8, 0, 0, 0 },
        { 0, 0, 3, 0, 0 },
        { 0, 6, 0, 0, 1 },
    };

    sparesify(Matrix);

    return 0;
}

/*

The following examples show how these matrixes are represented.

Examples:

Input : 0  0  0  0
        5  8  0  0
        0  0  3  0
        0  6  0  0

Solution: When the matrix is read row by
          row, the A vector is [ 5 8 3 6]
          The JA vector stores column indices
          of elements in A hence, JA = [ 0 1 2
           1]. IA[0] = 0. IA[1] = IA[0] + no
          of non-zero elements in row 0
          i.e 0 + 0 = 0.
          Similarly,
          IA[2] = IA[1] + 2 = 2
          IA[3] = IA[2] + 1 = 3
          IA[4] = IA[3]+1 = 4
          Therefore IA = [0 0 2 3 4]
          The trick is remember that IA[i]
          stores NNZ upto and not-including
          i row.

Input : 10  20  0  0  0  0
         0  30  0  4  0  0
         0   0 50 60 70  0
         0   0  0  0  0 80

Output :  A = [10 20 30 4 50 60 70 80],
         IA = [0 2 4 7 8]
         JA = [0  1 1 3 2 3 4 5]

*/
