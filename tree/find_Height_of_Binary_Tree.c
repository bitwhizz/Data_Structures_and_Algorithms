/*
 * level-orderTraversal.c
 *
 *  Created on: 29 Octuber 2025
 *      Author: saif
 * 
 *  Using level order traversal. This is similar to BFS of the Graph algorithms.
 * End of level is identified with NULL.
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

int FindHeightofBinaryTree(struct BinaryTreeNode *root)
{
    int level = 0,leftheight = 0,rightheight = 0;
    if(root == NULL){
        return 0;
    }
    printf("Nodes of the tree would be visited in level order : ");

    struct Queue *q = createQueue();
    enqueue(q,root);

    while(!isEmptyQueue(q))
    {
        struct Qnode *current = dequeue(q);
        printf("%d",current->treeNode->data);

        if(current->treeNode->left != NULL){
            enqueue(q,current->treeNode->left);
            leftheight++;
        }

        if(current->treeNode->right != NULL){
            enqueue(q,current->treeNode->right);
            rightheight++;
        }
    }

    if(leftheight < rightheight)
    {
        level = rightheight;
    }
    else{
        level = leftheight;
    }
    printf("\n");

    //Free the queue memory
    DeleteQueue(q);

    return level;
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
  root->left->left->left  = createnode(8);   //testing left subtree for tree height


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
  printf("tree node  rrr: %x \n",root->left->left->left);
  printf("tree node  rlll: %x \n",root->left->left->left);
  
  root->left->left->left->left= NULL;
  //root->left->left->left= NULL;
  root->left->left->right = NULL;
  root->left->right->left  = NULL;
  root->left->right->right  = NULL;
  root->right->left->left = NULL;
  root->right->left->right = NULL;
  root->right->right->left = NULL;
  root->right->right->right = NULL;


   printf("Height of the Nodes of the tree would be  :  %d \n", FindHeightofBinaryTree(root));


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
tree node  r: 1f47010 
tree node  rl: 1f47030 
tree node  rll: 1f47070 
tree node  rlr: 1f47090 
tree node  rr: 1f47050 
tree node  rrl: 1f470b0 
tree node  rrr: 1f470d0 
tree node  rrr: 1f470f0 
tree node  rlll: 1f470f0 
Nodes of the tree would be visited in level order : 12345678
Height of the Nodes of the tree would be  :  4
*/
