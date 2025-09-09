/*


*/

//Tue Jun 26 21:59:47 IST 2018

#include <stdio.h>
#include <stdlib.h>		//<stdlib.h> contains declaration of malloc() and free()
#include<stdbool.h>

struct CNode
{
int g_value;
struct  CNode *next;
};

void DeleteLastNode(struct CNode **head)
{
	struct CNode *temp = *head, *current = *head;

	if(*head == NULL)
	{
		printf("List Empty"); return;
	}

	while(current->next != *head)
	{
		temp = current;
		current = current->next;
	}

	temp->next = current->next;
	free(current);
	return;
}

void DeleteFrontNode(struct CNode **head){
	struct CNode *temp = *head, *current = *head;

	if(*head == NULL){
		printf("List Empty");
		return;
	}

	while(current->next != *head)
		current=current->next;

	current->next = (*head)->next;
	*head = (*head)->next;

	free(temp);
	return;
}

void insert_at_end(struct CNode** head_ref,int data)
{
	struct CNode *new_node = (struct CNode *)malloc(sizeof(struct CNode));	//new node to be added
	struct CNode *temp=*head_ref;	//temporary node use to get end point

	new_node->g_value=data;
	new_node->next=*head_ref;

	if(*head_ref!=NULL){	//if already nodes are on list

		while(temp->next!=*head_ref)
			temp=temp->next;
		temp->next=new_node;
	}
	else{			//if list is empty
		new_node->next=new_node;
	}
}

void insert_at_begining(struct CNode** head_ref,int data)
{
	struct CNode *new_node = (struct CNode *)malloc(sizeof(struct CNode));	//new node to be added
	struct CNode *temp=*head_ref;	//temporary node use to get end point

	new_node->g_value=data;
	new_node->next=*head_ref;

	if(*head_ref!=NULL){	//if already nodes are on list

		while(temp->next!=*head_ref)
			temp=temp->next;
		temp->next=new_node;
	}
	else{			//if list is empty
		new_node->next=new_node;
	}
	*head_ref=new_node;
}


void print_list(struct CNode* head)
{
	struct CNode *temp=head;

	if(head!=NULL){
		do{
			printf("Node - %d \t",temp->g_value);
			temp=temp->next;
		}while(temp!=head);
	}
}

int main(void)
{
	struct CNode *head=NULL;

	insert_at_begining(&head,5);
	insert_at_begining(&head,1);
	insert_at_begining(&head,2);
	insert_at_begining(&head,3);
	insert_at_begining(&head,4);

	insert_at_end(&head,6);
	insert_at_end(&head,7);
	insert_at_end(&head,8);
	insert_at_end(&head,9);
	insert_at_end(&head,10);


	printf("\n");

	DeleteLastNode(&head);
	DeleteFrontNode(&head);

	print_list(head);

	printf("\n");

return 0;
}
