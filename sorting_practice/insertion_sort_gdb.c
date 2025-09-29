/*
 * insertion_sort.c
 *
 *  Created on: 24-May-2019
 *      Author: saifullabaig
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


// C program for insertion sort
#include <math.h>
#include <stdio.h>

/*
 *
Loop from i = 1 to n-1.
……a) Pick element arr[i] and insert it into sorted sequence arr[0…i-1]

sorted array <----- unsorted array

*/

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];

        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        } //This while loop have sub-iterations till condition becomes false.

        arr[j + 1] = key;
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Driver program to test insertion sort */
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 ,9,9};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}


/*

As with growing complexity of the code / to declutter the logics of the program.
the spiral matrix program will go hand in hand with the gdb debugger on linux command line.asm

We can compile it with gcc -g -o0 spiral_matrix_gdb.c -o ./exe

  * The -g flag compiles the program with debugging symbols, which is going to make it a lot easier to look at our variables.
  * -o0 tells gcc to turn off optimizations So that the variables won't get optimized out.

run or r - Executes the program from start to end.
break or b - Sets a breakpoint on a particular line. Ex: b main / b 19 (line number) / b spiral_matrix_gdb.c:19 /b _func_name_ 

disable - Disables a breakpoint
enable - Enables a disabled breakpoint.
next or n - Executes the next line of code without diving into functions.
step - Goes to the next instruction, diving into the function.
list or l - Displays the code, if code has > 10 lines , one need to use the list command multiple times.
print or p - Displays the value of a variable.
quit or q - Exits out of GDB.
clear - Clears all breakpoints.
continue or c - Continues normal execution
backtrace or bt - show the trace of where you are currently. which function you are in . print stack back trace.
                - optiontionally you can move the call stack using up and doen commands.
finish - Run till exit

inside a function , variation of the info command prints the arguments passed to that function
info args , info args , info locals , info stack , info regsters , frame 

print variable-name - Print value sorted in variable. Ex: p i

start gdb using ,

$ gdb ./test

break and run , use the above commands to navigate through the code.

(gdb) b main / line number
(run) run

(gdb) print *array_name@size
(gdb) c
(gdb) n
(gdb) s

(gdb) p *arr@n
$6 = {12, 11, 13, 5, 6, 9, 9}
(gdb) c
Continuing.

Breakpoint 4, insertionSort (arr=0x7fffffffdbb0, n=7) at sorting_practice/insertion_sort.c:43
43	        while (j >= 0 && arr[j] > key) {
(gdb) info local
i = 1
key = 11
j = 0
(gdb) c
Continuing.

Breakpoint 3, insertionSort (arr=0x7fffffffdbb0, n=7) at sorting_practice/insertion_sort.c:36
36	        key = arr[i];
(gdb) p *arr@n
$7 = {11, 12, 13, 5, 6, 9, 9}
(gdb) c
Continuing.

Breakpoint 4, insertionSort (arr=0x7fffffffdbb0, n=7) at sorting_practice/insertion_sort.c:43
43	        while (j >= 0 && arr[j] > key) {
(gdb) info local
i = 2
key = 13
j = 1
(gdb) c
Continuing.

Breakpoint 3, insertionSort (arr=0x7fffffffdbb0, n=7) at sorting_practice/insertion_sort.c:36
36	        key = arr[i];
(gdb) p *arr@n
$8 = {11, 12, 13, 5, 6, 9, 9}
(gdb) c
Continuing.

Breakpoint 4, insertionSort (arr=0x7fffffffdbb0, n=7) at sorting_practice/insertion_sort.c:43
43	        while (j >= 0 && arr[j] > key) {
(gdb) info local
i = 3
key = 5
j = 2
(gdb) c
Continuing.

Breakpoint 3, insertionSort (arr=0x7fffffffdbb0, n=7) at sorting_practice/insertion_sort.c:36
36	        key = arr[i];
(gdb) p *arr@n
$9 = {5, 11, 12, 13, 6, 9, 9}
(gdb) c
Continuing.

Breakpoint 4, insertionSort (arr=0x7fffffffdbb0, n=7) at sorting_practice/insertion_sort.c:43
43	        while (j >= 0 && arr[j] > key) {
(gdb) info local
i = 4
key = 6
j = 3
(gdb) c
Continuing.

Breakpoint 3, insertionSort (arr=0x7fffffffdbb0, n=7) at sorting_practice/insertion_sort.c:36
36	        key = arr[i];
(gdb) p *arr@n
$10 = {5, 6, 11, 12, 13, 9, 9}
(gdb) c
Continuing.

Breakpoint 4, insertionSort (arr=0x7fffffffdbb0, n=7) at sorting_practice/insertion_sort.c:43
43	        while (j >= 0 && arr[j] > key) {
(gdb) info local
i = 5
key = 9
j = 4
(gdb) c
Continuing.

Breakpoint 3, insertionSort (arr=0x7fffffffdbb0, n=7) at sorting_practice/insertion_sort.c:36
36	        key = arr[i];
(gdb) p *arr@n
$11 = {5, 6, 9, 11, 12, 13, 9}
(gdb) c
Continuing.

Breakpoint 4, insertionSort (arr=0x7fffffffdbb0, n=7) at sorting_practice/insertion_sort.c:43
43	        while (j >= 0 && arr[j] > key) {
(gdb) info local
i = 6
key = 9
j = 5
(gdb) c
Continuing.
5 6 9 9 11 12 13 

*/