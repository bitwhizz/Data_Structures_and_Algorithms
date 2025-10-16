/*
How many times is a sorted array rotated.

2, 3, 5, 8, 11, 12  -- Sorted array

12, 2, 3, 5, 8, 11  -- Rotated once

11, 12, 2, 3, 5, 8 --Rotated twice ( Circularly sorted)

No of rotations = index of min element

Time Complexity -- O(logn)
*/

#include <stdio.h>

int FindRotationCount(int A[],int n)
{
    //Using Binary search
    int low = 0 , high = n-1;

    while(low <= high)
    {
        if(A[low] <= A[high]) return low; //case 1

        int mid = (low + high)/2;

        int next = (mid +1)%n , prev = (mid+n-1)%n;
        if(A[mid] <= A[next] && A[mid] <= A[prev])  //case 2
        return mid;
        else if(A[mid] <= A[high]) high = mid -1; //case 3
        else if(A[mid >= A[low]]) low = mid +1; //case 4
    }
    return -1;
}

int main()
{
    int A[] = {15,22,23,28,31,38,5,6,7,8,9,10,12};
    int count = FindRotationCount(A,sizeof(A)/sizeof(A[0]));

    printf("The array is rotated %d times \n",count);
}