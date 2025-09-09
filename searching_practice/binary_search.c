/*
 * binary_search.c
 *
 *  Created on: 30-May-2019
 *      Author: saifullab
 */

/*
 *
 * The idea of binary search is to use the information that
 * the array is sorted and reduce the time complexity to O(Log n).
 *
 * We basically ignore half of the elements just after one comparison.
 * Compare x with the middle element.
 * If x matches with middle element, we return the mid index.
 * Else If x is greater than the mid element,
 * then x can only lie in right half subarray after the mid element.
 *  So we recur for right half.
 * Else (x is smaller) recur for the left half.
 *
 */

// C program to implement recursive Binary Search
#include <stdio.h>

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int L, int R, int x)
{
	if(R>=L){

		int mid = L + (R-L)/2;

	   // If the element is present at the middle itself

		if(arr[mid]==x)
			return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
		if(arr[mid]>x)
			return binarySearch(arr,L,mid-1,x);

		if(arr[mid]<x)
			return binarySearch(arr,mid+1,R,x);
	}

    // We reach here when element is not
    // present in array

	return -1;
}


// A iterative binary search function. It returns location of x in
// given array arr[l..r] if present, otherwise -1
int itr_binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r)
	{
		int m = l + (r-l)/2;  //find the middle element

		// Check if x is present at mid
		if (arr[m] == x)
				return m;

		// If x greater, ignore left half
		if (arr[m] < x)
				l = m + 1;

		// If x is smaller, ignore right half
		else
				r = m - 1;
	}

// if we reach here, then element was not present
return -1;
}

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 ,50 ,60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 50;
    int result1 = itr_binarySearch(arr, 0, n - 1, x);
    (result1 == -1) ? printf("Element is not present in array\n")
                   : printf("Element is present at index %d\n",
                            result1);
		int result = binarySearch(arr, 0, n - 1, x);
		(result == -1) ? printf("Element is not present in array\n")
					         : printf("Element is present at index %d\n",
									           result);    return 0;
}
