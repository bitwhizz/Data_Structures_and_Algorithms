#include<stdio.h>
#include<stdlib.h>

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

//just a counter while traversing the node

int get_count(struct NODE* current)
{
	unsigned int count=0;

	while(current!=NULL)
	{
		current=current->next;
		count++;
	}
	return count;
}

int main(void)
{
	struct NODE *head=NULL;

	front(&head,1);
	front(&head,2);
	front(&head,3);
	front(&head,4);
	front(&head,5);

	printf("no of nodes in lnkd list=%d\n",get_count(head));

	return 0;
}
