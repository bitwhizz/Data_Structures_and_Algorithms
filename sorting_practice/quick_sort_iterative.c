// An iterative implementation of quick sort
/*
Algorithm	-->Time Complexity(Worst case)
Selection Sort		O(n^2)
Bubble Sort		    O(n^2)
Insertion Sort	  O(n^2)
Heap Sort		      O(n log(n))
Quick Sort		    O(n^2)
Merge Sort	      O(n log(n))
Bucket Sort		    O(n^2)
Radix Sort	      O(nk)

1) Partition process is same in both recursive and iterative.
The same techniques to choose optimal pivot_index can also be applied to iterative version.

2) To reduce the stack size, first push the indexes of smaller half.

3) Use insertion sort when the size reduces below a experimentally calculated threshold.
*/

#include <stdio.h>
#include <string.h>

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function is same in both iterative and recursive*/
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];     //taking the last value in the array as initial pivot_index
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot) {
            i++;              // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* A[] --> Array to be sorted,
   low  --> Starting index,
   high  --> Ending index */
void quickSortIterative(int arr[], int low, int high)
{
    // Create an auxiliary stack
    int stack[high - low + 1];

    memset(stack,0,sizeof(stack));

    // initialize top of stack
    int top = -1;

    // push initial values of low and high to stack
    stack[++top] = low;
    stack[++top] = high;

    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop high and low
        high = stack[top--];
        low = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int pivot_index = partition(arr, low, high);

        // If there are elements on left side of pivot_index,
        // then push left side to stack
        if (pivot_index - 1 > low) {
            stack[++top] = low;
            stack[++top] = pivot_index - 1;
        }

        // If there are elements on right side of pivot_index,
        // then push right side to stack
        if (pivot_index + 1 < high) {
            stack[++top] = pivot_index + 1;
            stack[++top] = high;
        }
    }
}

// A utility function to print contents of arr
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}

// Driver program to test above functions
int main()
{
    int arr[] = { 4, 3, 5, 2, 1, 3, 2, 3 };
    int n = sizeof(arr) / sizeof(*arr);
    quickSortIterative(arr, 0, n - 1);
    printArr(arr, n);

    printf("\n");
    return 0;
}
