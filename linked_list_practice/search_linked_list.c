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

bool search(struct NODE* head,int key){

	struct NODE* current=head;

	while(current!=NULL){

		if(current->data==key)
			return true;

		current=current->next;
	}

	return false;
}

int main(void)
{
	struct NODE *head=NULL;

	front(&head,1);
	front(&head,2);
	front(&head,3);
	front(&head,4);
	front(&head,5);

	search(head,4)?printf("YES\n"):printf("NO\n");

	return 0;
}
