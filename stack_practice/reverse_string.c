/*
 * reverse_string.c
 *
 *  Created on: 07-Feb-2019
 *      Author: saifullab
 */


// C program to reverse a string using stack
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a stack
typedef struct
{
    int top;
    unsigned capacity;
    char* array;
}stack_t;

//creating the empty stack
stack_t* create_stack(unsigned capacity)
{
	stack_t* stack=(stack_t*)malloc(sizeof(stack_t));
	stack->capacity=capacity;
	stack->top=-1;
	stack->array=(char*)malloc((stack->capacity)*sizeof(char));

return stack;
}

// Stack is full when top is equal to the last index
int isFull(stack_t* stack)
{
 return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(stack_t* stack)
{
return stack->top==-1;
}

//add an item to stack and increase the value of top by 1
void push(stack_t *stack,char item)
{
	if(isFull(stack))
	return;

	stack->array[++stack->top]=item;
}

//Remove an item to stack and decrease the value of top by 1
char pop(stack_t *stack){

	if(isEmpty(stack))
	return CHAR_MIN;

	//return stack->array[stack->top]=0;
	//stack->top--;
	return stack->array[stack->top--];
}

// A stack based function to reverese a string
void reverse(char str[])
{
    // Create a stack of capacity
    //equal to length of string
    int i=0;
    int n = strlen(str);

    stack_t* stack = create_stack(n);

    // Push all characters of string to stack

    for (i = 0; i < n; i++)
        push(stack, str[i]);

    // Pop all characters of string and
    // put them back to str
    for (i = 0; i < n; i++)
        str[i] = pop(stack);
}

int main(void)
{
	char string[]="HELLO";

	printf("Reverse the string-->%s\n",string);

	reverse(string);

	printf("%s\n",string);

return 0;
}

