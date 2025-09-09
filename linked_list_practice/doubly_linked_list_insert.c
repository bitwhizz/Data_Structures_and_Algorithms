#include <stdio.h>
#include <stdlib.h>


struct DNode{
    int data;
    struct DNode *next;
    struct DNode *prev;
};

void Doubly_list_Insert(struct DNode **head,int data,int position){
    int k = 1;
    struct DNode *temp , *newNode;
    newNode = (struct DNode *)malloc(sizeof(struct DNode));

    if(!newNode){               //Always check for memory errors
        printf("Memmory Error");
        return;
    }

    newNode->data = data;
    if(position == 1 )        //inserting a node at the begining
    {
        newNode->next = *head;
        newNode->prev = NULL;

        if(*head)
            (*head)->prev = newNode;

        *head = newNode;
        return;
    }
    temp = *head;
    while((k < position - 1) && temp->next!=NULL){
        temp = temp->next;
        k++;
    }

    if(k!=position){
        printf("Desired position does not exist\n");
    }

    newNode->next = temp->next;
    newNode->prev=temp;

    if(temp->next)
        temp->next->prev=newNode;

    temp->next=newNode;
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

	printf("insert new node at (1) begining of node (2)Intermediate Node (3)append node at the end\n");
	scanf("%d",&opt);

	head->data=1;
	second->data=2;
	third->data=3;

	head->next=second;
	second->next=third;
	third->next=NULL;

	head->prev=NULL;
	second->prev=head;
	third->prev=second;

	printf("\nnodes values\n");
	if(opt==1){
        Doubly_list_Insert(&head,4,1);       
	}else if(opt==2){
        Doubly_list_Insert(&head,4,2);
	}else if(opt==3){
		Doubly_list_Insert(&head,4,4);
	}else{
		return 1;
	}

	traverse(head);

return 0;
}

