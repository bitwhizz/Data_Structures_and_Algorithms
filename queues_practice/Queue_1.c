// C program for array implementation of queue
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// A structure to represent a queue
typedef struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int* array;
}queue_t;

queue_t* create_queue(unsigned capacity)
{
	queue_t* queue=(queue_t*)malloc(sizeof(queue_t));
	
	queue->capacity=capacity;
	queue->front=queue->size=0;
	queue->rear=capacity-1;
	queue->array=(int*)malloc(queue->capacity*sizeof(int));

return queue;
}

// Queue is full when size becomes equal to the capacity 
bool isFull(queue_t* queue)
{  return (queue->size == queue->capacity);  }
 
// Queue is empty when size is 0
bool isEmpty(queue_t* queue)
{  return (queue->size == 0); }

 
// Function to add an item to the queue.  
// It changes rear and size
void enqueue(queue_t* queue, int item)
{
    if (isFull(queue))
        return;

//rear=9   9+1 -->10%10 =0
//rear=10  10+1-->11%10 =1 .....
    queue->rear = (queue->rear + 1) % queue->capacity;	
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;

    printf("%d enqueued to queue\n", item);
}

// Function to remove an item from queue. 
// It changes front and size
int dequeue(queue_t* queue)
{
    if (isEmpty(queue))
        return INT_MIN;

    int item = queue->array[queue->front];

	//front=0  0+1 -->1%10 = 0
    queue->front = (queue->front + 1) % queue->capacity;	 
    queue->size = queue->size - 1;

    return item;
}

// Function to get front of queue
int front(queue_t* queue)
{
    if (isEmpty(queue))
        return INT_MIN;

    return queue->array[queue->front];
}
 
// Function to get rear of queue
int rear(queue_t* queue)
{
    if (isEmpty(queue))
        return INT_MIN;

    return queue->array[queue->rear];
}


int main(void){

	printf ("Implementation of Queue\n");

	queue_t* queue=create_queue(10);

	if(queue!=NULL){
		printf("que is created\n");
		if(isFull(queue)==true){
			printf("que is full\n");
		}
		else{
			if(isEmpty(queue)==true){
				printf("que is empty\n\n");
			}
		}
	}


	//1112->8910->567->1235
	enqueue(queue,1234);
	enqueue(queue,567);
	enqueue(queue,8910);
	enqueue(queue,1112);

 	   printf("\nFront item is %d\n",front(queue));
 	   printf("Rear item is %d\n",rear(queue));

  //1112->8910->567->1235
	dequeue(queue);

 	   printf("\nAfter dequeued\n");
 	   printf("Front item is %d\n",front(queue));
 	   printf("Rear item is %d\n",rear(queue));

return 0;
}
