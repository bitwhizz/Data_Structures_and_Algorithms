/*
 * Give an algorithm for printing the level order data in reverse order.
 *
 *  Created on: 28 June 2026
 *      Author: saif
 * 
 *  
 * Visit the root
 * 
 * while traversiing level (keep all the elements at level +1 in queue)
 * 
 * Go to next level and visit all the nodes at that level.
 * 
 * Repeat this until all levels are completed
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct BinaryTreeNode{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};


struct Qnode{
    struct BinaryTreeNode* treeNode;
	struct Qnode* next;
};

struct Queue{
	struct Qnode* front,*rear;
};

struct StackNode{
    struct BinaryTreeNode* treeNode;
	  struct StackNode* next;
};

/* createnode() allocates a new node with the given data and NULL left and
   right pointers. */

struct BinaryTreeNode* createnode(int data)
{
  // Allocate memory for new node
  struct BinaryTreeNode* newNode = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));

  if (newNode == NULL)
  {
    perror("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  // Assign data to this node
  newNode->data = data;

  // Initialize left and right children as NULL
  newNode->left = NULL;
  newNode->right = NULL;

  return(newNode);
}

struct Qnode* new_node(struct BinaryTreeNode* treeNode){
    struct Qnode *temp = (struct Qnode*)malloc(sizeof(struct Qnode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    return temp;
}

struct Queue *createQueue(){
	struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue));
	q->front=q->rear=NULL;
	return q;
}

bool isEmptyQueue(struct Queue *q)
{
    //if the condition is true then 1 is returned else 0 is returned
    return (q->front == NULL);
}

void enqueue(struct Queue* q,struct BinaryTreeNode* treeNode){

	struct Qnode* temp=new_node(treeNode);

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

void DeleteQueue(struct Queue* q)
{
    struct Qnode* temp;
    while(q->front!=NULL){
        temp = q->front;
        q->front=q->front->next;
        free(temp);
    }
    free(q);
}

struct StackNode* createStackNode(struct BinaryTreeNode* treeNode)
{
  struct StackNode* newStackNode = (struct StackNode*)malloc(sizeof(struct StackNode));

  if(newStackNode == NULL)
  {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
  }

  newStackNode->treeNode = treeNode;
  newStackNode->next = NULL;
  return newStackNode;
}

/* Given a reference (pointer to pointer) to the head of a list and
   an int, inserts a new node on the front of the list. */
void push(struct StackNode** head_ref, struct BinaryTreeNode* treeNode)
{
    struct StackNode* new_node = createStackNode(treeNode);

	//assigning the address of the previous head to new node
	new_node->next=(*head_ref);

	//move the head to point to the new node
	(*head_ref) = new_node;
}

int isEmptystack(struct StackNode* head_ref)
{
  return (head_ref == NULL);
}

struct BinaryTreeNode* pop(struct StackNode** head_ref){

  if(isEmptystack(*head_ref))
  {
    return NULL;
  }

  struct StackNode *temp = *head_ref;
  struct BinaryTreeNode* poppedNode = temp->treeNode;

  *head_ref = (*head_ref)->next;
  free(temp);

  return poppedNode;
}


void levelOrderTraversalInReverse(struct BinaryTreeNode *root)
{
    if(root == NULL){
        return;
    }

    printf("Nodes of the tree would be visited in Level order : ");

    struct Queue *q = createQueue();
    struct StackNode *stack = NULL;
    enqueue(q,root);

    while(!isEmptyQueue(q))
    {
        struct Qnode *current = dequeue(q);

        if(current->treeNode->left != NULL){
            enqueue(q,current->treeNode->left);
        }

        if(current->treeNode->right != NULL){
            enqueue(q,current->treeNode->right);
        }
        push(&stack,current->treeNode);
    }
    while(!isEmptystack(stack))
    {
        printf("%d",pop(&stack)->data);
    }
    printf("\n");
    //Free the queue memory
    DeleteQueue(q);
}

int main()
{
     /*create root tree Node*/
  struct BinaryTreeNode *root = createnode(1);
  /* following is the tree after above statement

        1
      /   \
     NULL  NULL
  */


  root->left        = createnode(2);
  root->right       = createnode(3);
  /* 2 and 3 become left and right children of 1
           1
         /   \
        2      3
     /    \    /  \
    NULL NULL NULL NULL
  */


  root->left->left  = createnode(4);
  /* 4 becomes left child of 2
           1
       /       \
      2          3
    /   \       /  \
   4    NULL  NULL  NULL
  /  \
NULL NULL
*/

  root->left->right  = createnode(5);
  root->right->left  = createnode(6);
  root->right->right = createnode(7);



  /* 4 becomes left child of 2
                 1
             /       \
            2          3
          /   \       /  \
        4     5      6     7
      /  \   /  \   / \   / \
  NULL NULL NULL NULL NULL NULL   
*/
  printf("tree node  r: %x \n",root);
  printf("tree node  rl: %x \n",root->left);
  printf("tree node  rll: %x \n",root->left->left);
  printf("tree node  rlr: %x \n",root->left->right);
  printf("tree node  rr: %x \n",root->right);
  printf("tree node  rrl: %x \n",root->right->left);
  printf("tree node  rrr: %x \n",root->right->right);

  root->left->left->left = NULL;
  root->left->left->right = NULL;
  root->left->right->left  = NULL;
  root->left->right->right  = NULL;
  root->right->left->left = NULL;
  root->right->left->right = NULL;
  root->right->right->left = NULL;
  root->right->right->right = NULL;

  levelOrderTraversalInReverse(root);

  //getchar();

  free(root->right->right);
  free(root->right->left);
  free(root->left->right);
  free(root->left->left);
  free(root->right);
  free(root->left);
  free(root);

  return 0;
}


/*
tree node  r: 1bc6010 
tree node  rl: 1bc6030 
tree node  rll: 1bc6070 
tree node  rlr: 1bc6090 
tree node  rr: 1bc6050 
tree node  rrl: 1bc60b0 
tree node  rrr: 1bc60d0 
Nodes of the tree would be visited in order : 1234567

*/