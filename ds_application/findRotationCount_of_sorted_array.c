/*
How many times is a sorted array rotated.

2, 3, 5, 8, 11, 12  -- Sorted array

12, 2, 3, 5, 8, 11  -- Rotated once

11, 12, 2, 3, 5, 8 --Rotated twice ( Circularly sorted)

No of rotations = index of min element

Time Complexity -- O(n)
*/

#include <stdio.h>

int FindRotationCount(int A[],int n)
{
    //Linear search

    int min = A[0];
    int minIndex = 0;
    int index = 0;

    for(index = 1;index < n-1 ; index ++)
    {
        if(A[index] < min)
        {
            min = A[index];
            minIndex = index;

            return index;
        }
    }
    return 0;
}

int main()
{
    int A[] = {11,12,1,2,3,4,5,6,7,8,9,10};
    int count = FindRotationCount(A,sizeof(A)/sizeof(A[0]));

    printf("The array is rotated %d times \n",count);
}
