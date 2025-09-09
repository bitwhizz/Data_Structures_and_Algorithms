#include <stdio.h>
#include <stdlib.h>


struct DNode{
    int data;
    struct DNode *next;
    struct DNode *prev;
};

void Doubly_list_delete(struct DNode **head,int position){
    struct DNode *temp = *head,*temp2;
    int k=1;

    if(*head == NULL){
        printf("List is empty");
        return;
    }

    if(position == 1){
        *head = (*head)->next;

        if(*head != NULL)
            (*head)->prev = NULL;
            free(temp);
            return;
    }

    while((k<position) && temp->next!=NULL){
        temp = temp->next;
        k++;
    }

    if(k!=position-1){
        printf("Desired position does not exist\n");
    }

    temp2=temp->prev;
    temp2->next = temp->next;

    if(temp->next)      //Deletion from Intermediate Node
        temp->next->prev = temp2;

    free(temp);

    return;
}

void traverse(struct DNode* node)
{
	while(node!=NULL){	//continue till the node pointer reaches NULL

		printf("%d\n",node->data);
		node=node->next;
	}
}

int main(void)
{
    struct DNode * head = NULL,*second = NULL,*third = NULL;
	unsigned int opt=0;

  	// allocate 3 nodes in the heap  
	head = (struct DNode*)malloc(sizeof(struct DNode)); 
	second = (struct DNode*)malloc(sizeof(struct DNode));
	third = (struct DNode*)malloc(sizeof(struct DNode));

	head->data=1;
	second->data=2;
	third->data=3;

	head->next=second;
	second->next=third;
	third->next=NULL;

	head->prev=NULL;
	second->prev=head;
	third->prev=second;

	printf("\n list doubly linked list nodes\n");
	traverse(head);

	printf("insert new node at (1)first node (2) Intermediate node\n");
	scanf("%d",&opt);

	printf("\n delete nodes\n");
	if(opt==1){
        Doubly_list_delete(&head,1);
	}else if(opt==2){
        Doubly_list_delete(&head,2);
	}else{
		return 1;
	}

	traverse(head);

return 0;
}

