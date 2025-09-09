/*
 * priority_queue.c
 *
 *  Created on: 05-Mar-2019
 *      Author: saifullab
 */


#include <stdio.h>
#include <stdlib.h>

// Node
typedef struct node {
    int data;

    // Lower values indicate higher priority
    int priority;
    struct node* next;

} Node;


Node* new_node(int data ,int priority)
{
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->data=data;
	temp->priority=priority;
	temp->next=NULL;

	return temp;
}

// Return the value at head
int peek(Node** head)
{
    return (*head)->data;
}

// Removes the element with the
// highest priority form the list
void pop(Node** head)
{
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

//Function to push according to its priority
void push(Node** head, int d, int p){

	Node *start = (*head);

	//create new node
	Node *temp = new_node(d,p);

    // Special Case: The head of list has lesser
    // priority than new node. So insert new
    // node before head node and change head node.
	if((*head)->priority > p)
	{
     // Insert New Node before head
		temp->next = *head;
		(*head)=temp;
	}
	else{

		while(start->next!=NULL && start->next->priority < p){
			start=start->next;
		}

        // Either at the ends of the list
        // or at required position
        temp->next = start->next;
        start->next = temp;
	}
}

// Function to check is list is empty
int isEmpty(Node** head)
{
    return (*head) == NULL;
}

// Driver code
int main()
{
    // Create a Priority Queue
    // 7->4->5->6
    Node* pq = new_node(4, 1);
    push(&pq, 5, 2);
    push(&pq, 6, 3);
    push(&pq, 7, 5);

    while (!isEmpty(&pq)) {
        printf("%d ", peek(&pq));
        pop(&pq);
    }

    return 0;
}



