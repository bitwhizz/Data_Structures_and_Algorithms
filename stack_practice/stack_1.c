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

int main(void)
{
	int value=-2;
	char string='\0';

	printf("Reverse the string");
	stack_t *stack=create_stack(5);	//empty stack created

	//printf("\n0x%x\n",stack);
	printf("\n0x%x\n",stack->top);
	printf("0x%x\n",value);

	if(isFull(stack)==1){
		printf("0x%x\n",stack->top);
		printf("stack is full\n");
	}
	else{
		if(isEmpty(stack)==1){
			printf("0x%x\n",stack->top);
			printf("stack is empty\n");
			//printf("0x%x\n",INT_MIN);
		}
	}

	push(stack,'s');
	push(stack,'a');
	push(stack,'i');
	push(stack,'f');
	push(stack,'u');
	push(stack,'l');
	push(stack,'l');
	push(stack,'a');

	printf("%s\n",stack->array);

	string=pop(stack);
	printf("%c\n",string);
	string=pop(stack);
	printf("%c\n",string);
	string=pop(stack);
	printf("%c\n",string);
	string=pop(stack);
	printf("%c\n",string);
	string=pop(stack);
	printf("%c\n",string);

return 0;
}

