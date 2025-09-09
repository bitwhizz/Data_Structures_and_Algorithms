/*
 * array_stack.c
 *
 *  Created on: 07-Feb-2019
 *      Author: saifullab
 */

#include<stdio.h>

#define MAX_SIZE 101
int A[MAX_SIZE];
int top=-1;

void push(int x)
{

	if(top==MAX_SIZE-1){
		printf("Error: stack overflow\n");
		return;
	}
	A[++top]=x;
}

void pop(){
	if(top==-1){
		printf("Error: No element to pop");
		return;
	}
	top--;
}

void print()
{
	int i=0;

	printf("stack:");
	for(i=0;i<=top;i++){
		printf(" %d",A[i]);
	}
	printf("\n");
}

int main(){

	push(4);print();
	push(5);print();
	push(6);print();
	pop();print();
	push(7);print();
}
