/*
The stack could help in approaching this problem. This will be a two-step process:

   Pop the elements from the queue and insert into the stack.
   Pop the elements of the stack to insert back into the queue.
*/



#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Qnode{
	int key;
	struct Qnode* next;
};

struct Queue{
	struct Qnode* front,*rear;
};

struct Qnode* new_node(int key){
    struct Qnode *temp = (struct Qnode*)malloc(sizeof(struct Qnode));
    temp->key = key;
    temp->next = NULL;
    return temp;
}

struct Queue *createQueue(){
	struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue));
	q->front=q->rear=NULL;
	return q;
}

void enqueue(struct Queue* q,int key){

	struct Qnode* temp=new_node(key);

	if(q->rear==NULL)
	{
		q->rear=q->front=temp;
		return;
	}

	q->rear->next=temp;
	q->rear=temp;
}

struct Qnode* dequeue(struct Queue*q){

	if(q->front==NULL)
	   return NULL;

	struct Qnode*temp=q->front;
	q->front=q->front->next;

	if(q->front==NULL)
		q->rear=NULL;

	return temp;
}

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

// Utility function to print the queue
void Print(struct Queue* q)
{
  struct Qnode *n =NULL;
    do{
         n = dequeue(q);
        if (n != NULL)
          printf("Dequeued item is %d\n", n->key);
    }while(n != NULL);
}

// Function to reverse the queue
void reverseQueue(struct Queue* q)
{
    struct NODE *top=NULL;
    struct Qnode *n =NULL;

    do{
          n = dequeue(q);
      if (n != NULL){
        printf("Dequeued item is %d\n", n->key);
        push(&top,n->key);
      }
    }while (n!=NULL);

    while (peek(top)!=0) {
        enqueue(q,peek(top));
        pop(&top);
    }
}

int main()
{
    struct Queue *q = createQueue();

    if(q->front==NULL && q->rear==NULL )
    printf(" Queue is Empty\n");

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    enqueue(q, 70);
    enqueue(q, 80);
    enqueue(q, 90);
    printf(" Queue to be reversed\n");
    reverseQueue(q);
    printf(" Queue reversed\n");
    Print(q);

    return 0;
}
