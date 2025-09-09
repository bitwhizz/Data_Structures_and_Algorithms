/*
 * get_nth _node.c
 *
 *  Created on: 06-Feb-2019
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


int Get_nth_node(struct NODE* head,int index)
{
	struct NODE* current=head;
	unsigned int count=0;

	while(current!=NULL){

		if(count==index)
			return current->data;

		current=current->next;
		count++;
	}
return 0;
}

int main(void)
{
	struct NODE *head=NULL;

	front(&head,1);
	front(&head,2);
	front(&head,3);
	front(&head,4);
	front(&head,5);

	//5->4->3->2->1

	printf("The data at index is %d\n",Get_nth_node(head,0));

	return 0;
}
