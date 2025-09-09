/*
 * queue_using_ll.c
 *
 *  Created on: 11-Feb-2019
 *      Author: saifullab
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

int main()
{
    struct Queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    dequeue(q);
    dequeue(q);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    struct Qnode *n = dequeue(q);

    if (n != NULL)
      printf("Dequeued item is %d", n->key);
    return 0;
}
