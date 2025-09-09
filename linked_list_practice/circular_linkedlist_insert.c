/*
Operation	: Circular linked list 

Description : Circular limkedlist do not have ends.
			while traversing the linked list we should be carefull; 
			otherwise we will be traversing the list infinitely.abort

Function : Insert a node in Circular linked list , count number of nodes in Circular linked list.


Uing Gdb : Problem statement 

(gdb) 
insert_at_begining (head_ref=0x7fffffffdbc0, data=5) at circular_linkedlist.c:26
26	  struct NODE *new_node = (struct NODE *)malloc(sizeof(struct NODE));	//new node to be added
(gdb) 
__GI___libc_malloc (bytes=16) at malloc.c:2909

When GDB stops at the foo call, the step (s) command will step into std library function. 
While you can execute finish (fin) and then execute s again,it's time-consuming and distracting, 
especially when dealing with complex argument expressions. 

You can also ask GDB to ignore certain functions while stepping with the skip command

for skipping all the standard library files use below cmd
skip -gfi /usr/include/ 

skip delete -- Delete skip entries
skip disable -- Disable skip entries
skip enable -- Enable skip entries
skip file -- Ignore a file while stepping
skip function -- Ignore a function while stepping
info skip

for Profiling the program:
gcc -g -pg -o0 circular_linkedlist.c -o exe
./exe
gprof exe > profile.txt

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


int CL_lenght(struct CNode *head)
{
	struct CNode *current = head;
	int count = 0;

	if(head == NULL)
		return 0;

	do{
		current = current->next;
		count++;
	}while(current != head);

	return count;
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

	print_list(head);

	insert_at_end(&head,6);
	insert_at_end(&head,7);
	insert_at_end(&head,8);
	insert_at_end(&head,9);
	insert_at_end(&head,10);

	print_list(head);

	printf("\n");

	printf("Circular linked list node count %d \t",CL_lenght(head));
	
	printf("\n");

return 0;
}
