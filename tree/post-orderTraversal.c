/*
 * new_tree.c
 *
 *  Created on: 24 oct 2025
 *      Author: saif ulla baig

LRD : process left subtree , process right subtree and then process the current node data.

*/


#include <stdio.h>
#include <stdlib.h>


struct BinaryTreeNode{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
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

int isEmpty(struct StackNode* head_ref)
{
  return (head_ref == NULL);
}

struct BinaryTreeNode* pop(struct StackNode** head_ref){

  if(isEmpty(*head_ref))
  {
    return NULL;
  }

  struct StackNode *temp = *head_ref;
  struct BinaryTreeNode* poppedNode = temp->treeNode;

  *head_ref = (*head_ref)->next;
  free(temp);

  return poppedNode;
}

void PostOrderNonRecursive(struct BinaryTreeNode *root)
{   
    if(root == NULL)
    {
        return;
    }

    struct StackNode* stack1 = NULL;
    struct StackNode* stack2 = NULL;

    printf("Nodes of the tree would be visited in LRD order : ");
    
    push(&stack1,root);

    while(!isEmpty(stack1)){
        struct BinaryTreeNode* temp = pop(&stack1);
        push(&stack2,temp);

        if(temp->left)
            push(&stack1,temp->left);
        if(temp->right)
            push(&stack1,temp->right);
    }

    while(!isEmpty(stack2)){
        struct BinaryTreeNode *temp = pop(&stack2);
        printf("%d",temp->data);
    }

  printf("\n");
  
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

  PostOrderNonRecursive(root);

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
tree node  r: ac0010 
tree node  rl: ac0030 
tree node  rll: ac0070 
tree node  rlr: ac0090 
tree node  rr: ac0050 
tree node  rrl: ac00b0 
tree node  rrr: ac00d0 
Nodes of the tree would be visited in LRD order : 4526731
*/