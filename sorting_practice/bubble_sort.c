/*
 * bubble_sort.c
 *
 *  Created on: 24-May-2019
 *      Author: saifullab
Algorithm	-->Time Complexity(Worst case)
Selection Sort		O(n^2)
Bubble Sort		    O(n^2)
Insertion Sort	  O(n^2)
Heap Sort		      O(n log(n))
Quick Sort		    O(n^2)
Merge Sort	      O(n log(n))
Bucket Sort		    O(n^2)
Radix Sort	      O(nk)
 */


/*
 * smaller	elements	“bubble”	to	the	top	of	the	list
 */

// C program for implementation of Bubble sort
#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/* i= 0.....n-1
 * j = 0 ....n-i-1
 *
 * 0 ....n-1
 * 0 ....n-2
 * 0 ....n-3
 */


// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}

// Driver program to test above functions
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
