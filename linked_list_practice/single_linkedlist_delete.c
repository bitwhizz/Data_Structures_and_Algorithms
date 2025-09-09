//Sunday 24 June 2018 01:34:00  IST

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

/* Given a node prev_node, insert a new node after the given
   prev_node */
void insertAfter(struct NODE* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
       printf("the given previous node cannot be NULL");
       return;
    }

    /* 2. allocate new node */
    struct NODE* new_node =(struct NODE*) malloc(sizeof(struct NODE));

    /* 3. put in the data  */
    new_node->g_value  = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}

/* Given a reference (pointer to pointer) to the head
   of a list and an int, appends a new node at the end  */
void append(struct NODE** head_ref, int new_data)
{
    /*  allocate new node */
    struct NODE* new_node = (struct NODE*) malloc(sizeof(struct NODE));

    struct NODE *last = *head_ref;

    new_node->g_value  = new_data;
    new_node->next = NULL;

    /*  Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /*  Change the next of last node */
    last->next = new_node;
    return;
}

void deleteNode(struct NODE **head_ref, int key)
{
    // Store head node
    struct NODE* temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->g_value == key)
    {
        *head_ref = temp->next;   // Changed head
        free(temp);               // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->g_value != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp);  // Free memory
}

/* Function to delete the entire linked list */
void deleteList(struct NODE** head_ref)
{
   /* deref head_ref to get the real head */
   struct NODE* current = *head_ref;
   struct NODE* next;

   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }

   /* deref head_ref to affect the real head back
      in the caller. */
   *head_ref = NULL;
}


int main(void)
{
	unsigned int opt=0;
	struct NODE *head=NULL;
	struct NODE *second=NULL;
	struct NODE *third=NULL;

  	// allocate 3 nodes in the heap
	head = (struct NODE*)malloc(sizeof(struct NODE));
	second = (struct NODE*)malloc(sizeof(struct NODE));
	third = (struct NODE*)malloc(sizeof(struct NODE));

	printf("insert new node at (1)front (2)after second node (3)append (4)delete a node (5)delete_list\n");
	scanf("%d",&opt);

	head->g_value=1;
	second->g_value=2;
	third->g_value=3;

	head->next=second;
	second->next=third;
	third->next=NULL;

	printf("\nnodes values\n");

	if(opt==1){
		front(&head,4);
	}else if(opt==2){
		insertAfter(second,4);
	}else if(opt==3){
		append(&head,4);
	}
	else if(opt==4){
		deleteNode(&head,2);
	}
	else if(opt==5){
		 deleteList(&head);
	}else{
		return 1;
	}

	traverse(head);
return 0;
}
