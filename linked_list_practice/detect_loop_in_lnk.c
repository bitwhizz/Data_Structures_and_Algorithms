/*
 * detect_loop_in_lnk.c
 *
 *  Created on: 07-Feb-2019
 *      Author: saifullab
 */


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct NODE
{
	int data;
	struct NODE * next;
};

void front(struct NODE **head_ref,int data) {

	struct NODE *new_node=(struct NODE *)malloc(sizeof(struct NODE));

	new_node->data=data;
	new_node->next=*head_ref;

	*head_ref=new_node;
}

/*Floyd’s Cycle-Finding Algorithm:
This is the fastest method. Traverse linked list using two pointers.
Move one pointer by one and other pointer by two.
 If these pointers meet at same node then there is a loop.
 If pointers do not meet then linked list doesn’t have loop.*/

struct NODE* detect_node(struct NODE *head)
{
	struct NODE* slow_ptr=head,*fast_ptr=head;

	while(slow_ptr && fast_ptr && fast_ptr->next){
		slow_ptr=slow_ptr->next;
		fast_ptr=fast_ptr->next->next;

		if(slow_ptr==fast_ptr){
			printf("loop detected\n");
			return fast_ptr;
		}
	}

	return NULL;
}

int main(void)
{
	struct NODE *head=NULL,*temp=NULL,*temp2=NULL;

	front(&head,1);
	front(&head,2);
	front(&head,3);
	front(&head,4);
	front(&head,5);
	front(&head,3);
	front(&head,4);
	front(&head,5);

	//loop for test
	temp=head;
	temp=temp->next->next;

	head->next->next->next->next->next->next->next->next=temp;

	temp2=detect_node(head);
	temp2->next=NULL;	//Eliminate loop

	detect_node(head);

	return 0;
}
