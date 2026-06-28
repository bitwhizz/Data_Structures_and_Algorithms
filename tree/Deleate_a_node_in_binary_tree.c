/*
 * Give an algorithm for deleating an element from binary tree.
 *
 *  Created on: 28 June 2026
 *      Author: saif
 * 
 *  The deletion of a node in binary tree can be implemented as 
 * 
 *      starting at root , find the node which we want to delete.
 *      Find the deepest node int the tree.
 *      Replace the deepest node's data with node to be deleted.
 *      Then deleate the deepest node.
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

void deleteDeepest(struct BinaryTreeNode* root,struct BinaryTreeNode* dNode)
{
    struct Queue *q = createQueue();
    enqueue(q,root);

    while(!isEmptyQueue(q))
    {
        struct Qnode *current = dequeue(q);

        //if current Node is the deepest Node , delete it
        if(current->treeNode == dNode){
            current->treeNode = NULL;
            free(dNode);
            return;
        }

        //Check the right child first
        if(current->treeNode->right != NULL){
            if(current->treeNode->right == dNode)
            {
                current->treeNode->right = NULL;
                free(dNode);
                return;
            }
            enqueue(q,current->treeNode->left);
        }

        //check the left child
        if(current->treeNode->left != NULL){
            if(current->treeNode->left == dNode)
            {
                current->treeNode->left = NULL;
                free(dNode);
                return;
            }            
            enqueue(q,current->treeNode->left);
        }
    }
    //Free the queue memory
    DeleteQueue(q);
    return;
}

struct BinaryTreeNode* deletion(struct BinaryTreeNode *root,int key)
{
    if(root == NULL){
        return NULL;
    }

    if(root->left == NULL && root->right == NULL){
        //if the root node is the key, delete it
        if(root->data == key)
            return NULL;
        else
            return root;
    }

    printf("Node data of the tree is deleted at the deepest node : ");

    struct Queue *q = createQueue();
    enqueue(q,root);
    struct BinaryTreeNode *keynode = NULL;
    struct Qnode *current = NULL;

    while(!isEmptyQueue(q))
    {
        current = dequeue(q);

        //if current node is keynode
        if(current->treeNode->data == key){
            keynode = current->treeNode;
            printf("%d",keynode->data);
        }

        if(current->treeNode->left != NULL){
            enqueue(q,current->treeNode->left);
        }

        if(current->treeNode->right != NULL){
            enqueue(q,current->treeNode->right);
        }
    }

    if(keynode != NULL){
        //strore the data of the deepest node
        int x = current->treeNode->data;

        //Replace the key node data with deepest node's data
        keynode->data = x;

        //Deleate the deepest node
        deleteDeepest(root,current->treeNode);
    }
    printf("\n");
    //Free the queue memory
    DeleteQueue(q);

    return root;
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

  deletion(root,3);

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