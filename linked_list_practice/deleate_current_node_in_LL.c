/*
We	are	given	a	pointer	to	a	node	(not	the	tail	node)	in	a	singly	linked	list.	Delete
that	node	from	the	linked	list.

To	delete	a	node,	we	have	to	adjust	the	next	pointer	of	the	previous	node	to	point	to	the
next	node	instead	of	the	current	one.	Since	we	don’t	have	a	pointer	to	the	previous	node,	we	can’t
redirect	its	next	pointer.	So	what	do	we	do?	We	can	easily	get	away	by	moving	the	data	from	the
next	node	into	the	current	node	and	then	deleting	the	next	node.
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

		printf("%d -> ",node->g_value);
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

void delete(struct NODE* node){
  struct NODE *temp = node->next;

  node->g_value = node->next->g_value;

  node->next = temp->next;

  free(temp);
}

int main(void)
{
	struct NODE *head=NULL;

		front(&head,3);
		front(&head,2);
		front(&head,6);
		front(&head,7);
    front(&head,9);
    front(&head,4);
    front(&head,1);

    printf("\nlinked list before deleate operation\n");
	  traverse(head);

    delete(head->next->next);

    printf("\nlinked list After deleate operation\n");
	  traverse(head);
    printf("\n");

return 0;
}
