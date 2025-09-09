/*
 * segregate_even_odd.c
 *
 *  Created on: 12-Jun-2019
 *      Author: saifullab
 */


/*
 *
 * The idea is to get pointer to the last node of list.
 *  And then traverse the list starting from the head node and
 * move the odd valued nodes from their current position to end of the list
 *
 * track the list by using 4 pointers evenhead,evenlast,oddhead,oddlast
 *
 */

#include <stdio.h>
#include <stdlib.h>		//<stdlib.h> contains declaration of malloc() and free()


struct NODE
{
	int g_value;
	struct NODE *next;
};


void traverse(struct NODE* node)
{

	while(node!=NULL){	//continue till the node pointer reaches NULL

		printf("%d\n",node->g_value);
		node=node->next;
	}
}

/* Given a reference (pointer to pointer) to the head of a list and
   an int, inserts a new node on the front of the list. */
void front(struct NODE** head_ref, int new_data)
{
    struct NODE* new_node = (struct NODE*) malloc(sizeof(struct NODE));

	new_node->g_value=new_data;

	//assigning the address of the previous head to new node
	new_node->next=(*head_ref);

	//move the head to point to the new node
	(*head_ref)=new_node;
}


void segregate_even_odd(struct NODE **headref){

	struct NODE *current=*headref;
	struct NODE *evenhead=NULL,*oddhead=NULL,*evenlast=NULL,*oddlast=NULL;

	while(current!=NULL){

		if(current->g_value %2 == 0){

			if(evenhead==NULL){
				evenhead=evenlast=current;
			}
			else{
				evenlast->next=current;
				evenlast=current;
			}
		}
		else{
			if(oddhead==NULL){
				oddhead=oddlast=current;
			}
			else{
				oddlast->next=current;
				oddlast=current;
			}
		}
		current=current->next;
	}
	evenlast->next=oddhead;
	oddlast->next=NULL;

	*headref=evenhead;
}

int main(void)
{
	struct NODE *head=NULL;

	front(&head,1);
	front(&head,2);
	front(&head,4);
	front(&head,3);
	front(&head,6);
	front(&head,8);
	front(&head,7);
	front(&head,10);

	segregate_even_odd(&head);

	traverse(head);
return 0;
}

