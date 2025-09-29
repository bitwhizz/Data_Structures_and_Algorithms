/*
 * selection_sort.c
 *
 *  Created on: 02-Apr-2019
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

/*comparision sorting--in place sorting
 *
 * compare and swap the minimum number in unsorted array
 * to first position of unsorted array
 *
 * arr[] = 64 25 12 22 11

// Find the minimum element in arr[0...4]
// and place it at beginning
11 25 12 22 64

// Find the minimum element in arr[1...4]
// and place it at beginning of arr[1...4]
11 12 25 22 64

// Find the minimum element in arr[2...4]
// and place it at beginning of arr[2...4]
11 12 22 25 64

// Find the minimum element in arr[3...4]
// and place it at beginning of arr[3...4]
11 12 22 25 64 */

#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void SelectionSort(int A[],int n)
{
	int i,j,min;

	for(i=0;i < n-1;i++)
	{
		//ith position 0,1,2,3,4....n-1		
		min = i;			

		//jth position 1,2,3,4....n
		for(j=i+1; j<n; j++)
		{
			if(A[j] < A[min]){
				min = j;
			}
		}

		swap(&A[min],&A[i]);
	}
}

int main()
{
	int i=0;

	int A[]={5,6,4,3,7,2};

	int n = sizeof(A)/sizeof(A[0]);

	SelectionSort(&A[0],n);

	for(i=0;i<6;i++){
		printf("%d\t",A[i]);
	}

	printf("\n");

	return 0;
}

/*
(gdb) print *A@n
$2 = {5, 6, 4, 3, 7, 2}
(gdb) c
Continuing.

Breakpoint 2, SelectionSort (A=0x7fffffffdc90, n=6)
    at sorting_practice/selection_sort.c:66
66			swap(&A[min],&A[i]);
(gdb) info local
i = 0
j = 6
min = 5
(gdb) c
Continuing.

Breakpoint 1, SelectionSort (A=0x7fffffffdc90, n=6)
    at sorting_practice/selection_sort.c:59
59			for(j=i+1; j<n; j++)
(gdb) print *A@n
$3 = {2, 6, 4, 3, 7, 5}
(gdb) c
Continuing.

Breakpoint 2, SelectionSort (A=0x7fffffffdc90, n=6)
    at sorting_practice/selection_sort.c:66
66			swap(&A[min],&A[i]);
(gdb) info local
i = 1
j = 6
min = 3
(gdb) c
Continuing.

Breakpoint 1, SelectionSort (A=0x7fffffffdc90, n=6)
    at sorting_practice/selection_sort.c:59
59			for(j=i+1; j<n; j++)
(gdb) print *A@n
$4 = {2, 3, 4, 6, 7, 5}
(gdb) c
Continuing.

Breakpoint 2, SelectionSort (A=0x7fffffffdc90, n=6)
    at sorting_practice/selection_sort.c:66
66			swap(&A[min],&A[i]);
(gdb) info local
i = 2
j = 6
min = 2
(gdb) c
Continuing.

Breakpoint 1, SelectionSort (A=0x7fffffffdc90, n=6)
    at sorting_practice/selection_sort.c:59
59			for(j=i+1; j<n; j++)
(gdb) print *A@n
$5 = {2, 3, 4, 6, 7, 5}
(gdb) c
Continuing.

Breakpoint 2, SelectionSort (A=0x7fffffffdc90, n=6)
    at sorting_practice/selection_sort.c:66
66			swap(&A[min],&A[i]);
(gdb) info local
i = 3
j = 6
min = 5
(gdb) c
Continuing.

Breakpoint 1, SelectionSort (A=0x7fffffffdc90, n=6)
    at sorting_practice/selection_sort.c:59
59			for(j=i+1; j<n; j++)
(gdb) print *A@n
$6 = {2, 3, 4, 5, 7, 6}
(gdb) c
Continuing.

Breakpoint 2, SelectionSort (A=0x7fffffffdc90, n=6)
    at sorting_practice/selection_sort.c:66
66			swap(&A[min],&A[i]);
(gdb) info local
i = 4
j = 6
min = 5
(gdb) c
Continuing.
2	3	4	5	6	7	

*/