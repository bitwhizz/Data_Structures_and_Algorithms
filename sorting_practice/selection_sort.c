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

	return 0;
}


/*
A spiral matrix is n x n square matrix formed by placing the numbers 1,2,3,4......n^2 in spiral form starting form the leftmost column and topmost row.
asmSpiral matrices can exist for both even and odd values of n.
The spiral matrices for n = 3 , n = 4 , n =7 are shown below - n = 3 , n = 4 , n = 7

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

*/
