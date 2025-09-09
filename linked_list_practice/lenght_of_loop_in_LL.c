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

// Returns count of nodes present in loop.
unsigned int count_nodes(struct NODE* n)
{
  struct NODE* temp = n;
  unsigned int count = 1;
  while(temp->next != n)
  {
    count++;
    temp = temp->next;
  }
  return count;
}

/* This function detects and counts loop
   nodes in the list. If loop is not there
   in then returns 0 */

unsigned int count_nodes_in_loop(struct NODE *head)
{
	struct NODE* slow_ptr=head,*fast_ptr=head;

	while(slow_ptr && fast_ptr && fast_ptr->next){
		slow_ptr=slow_ptr->next;
		fast_ptr=fast_ptr->next->next;

		if(slow_ptr==fast_ptr){
      return count_nodes(slow_ptr);
		}
	}

	return 0;
}

int main(void)
{
	struct NODE *head=NULL,*temp=NULL;

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

    /* Create a loop for testing */
	head->next->next->next->next->next->next->next->next=temp;

	printf("%d\n",count_nodes_in_loop(head));

	return 0;
}
