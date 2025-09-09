//Sunday 24 June 2018 

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

int main(void)
{
	struct NODE *head=NULL;
	struct NODE *second=NULL;
	struct NODE *third=NULL;

  	// allocate 3 nodes in the heap  
	head = (struct NODE*)malloc(sizeof(struct NODE)); 
	second = (struct NODE*)malloc(sizeof(struct NODE));
	third = (struct NODE*)malloc(sizeof(struct NODE));

	printf("Enter value to first element of linked list \n");
	scanf("%d", &head->g_value);

	//head->g_value=1;
	second->g_value=2;
	third->g_value=3;

	head->next=second;
	second->next=third;
	third->next=NULL;	

	//printf("%d\n",head->g_value);
	traverse(head);

return 0;
}













