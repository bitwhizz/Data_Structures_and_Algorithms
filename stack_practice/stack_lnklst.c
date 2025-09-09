#include<stdio.h>
#include<stdlib.h>

struct NODE{
	int data;
	struct NODE* next;
};


/* Given a reference (pointer to pointer) to the head of a list and
   an int, inserts a new node on the front of the list. */
void push(struct NODE** head_ref, int new_data)
{
    struct NODE* new_node = (struct NODE*) malloc(sizeof(struct NODE));

	new_node->data=new_data;

	//assigning the address of the previous head to new node
	new_node->next=(*head_ref);

	//move the head to point to the new node
	(*head_ref)=new_node;
}

void pop(struct NODE** head_ref)
{
	struct NODE *temp=*head_ref;

	*head_ref=temp->next;

	free(temp);
}

int peek(struct NODE* head_ref){
	struct NODE *temp=head_ref;

	if(temp!=NULL)
		return temp->data;
	else
		return 0;
}

int main(){

	struct NODE *top=NULL;

	push(&top,12);
	push(&top,22);
	push(&top,33);
	push(&top,44);

	printf("%d\n",peek(top));

	pop(&top);

	printf("%d\n",peek(top));

	pop(&top);

	printf("%d\n",peek(top));

	pop(&top);

	printf("%d\n",peek(top));

	pop(&top);

	printf("%d\n",peek(top));

}
